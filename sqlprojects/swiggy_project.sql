select * from sales;
select * from product;
select * from goldusers_signup;
select * from users;

--1 total amount spent by each customer  

select s.userid ,sum(p.price) as total from sales as s
join product as p 
on p.product_id = s.product_id
group by s.userid

--2 how days each customer visited swiggy

select userid,count(created_date) days  from sales 
group by userid

--3 1st product purchasred by each customer

select s.*,p.product_name from
(select userid,created_date,product_id,rank() over(partition by userid order by created_date) as first_purchase
from sales) as s 
join product as p on s.product_id = p.product_id
where s.first_purchase = 1 

--4 most purchased product and how many times by each

with temp as
(select product_id from sales group by product_id order by count(product_id) desc 
limit 1 )
select userid,count(product_id) as count from sales where product_id=(select product_id from temp) group by userid 

--5 most popular product for each customer

select s.userid,s.product_id from
(select userid,product_id,rank() over(partition by userid order by count(product_id) desc) as ranked from sales group by userid, product_id) as s
where s.ranked = 1

--6 first product after becoming gold_member

select sd.* from
(select s.*,rank() over(partition by userid order by created_date) as ranked from sales as s
where created_date > (select gold_signup_date from goldusers_signup as g
where g.userid = s.userid)) as sd
where ranked = 1

--7 order just before the customer became a member

select p.* 
from (select s.userid,s.product_id,rank() over(partition by s.product_id order by s.created_date desc) as ranked from sales as s
join goldusers_signup as gu
on gu.userid = s.userid
where s.created_date <= gu.gold_signup_date) as p
where p.ranked=1

--8 total orders and amount spent before becoming gold member

select s.userId, count(s.product_id) as no_of_purchasings ,sum(p.price) as money_spent from sales as s
join product as p on p.product_id = s.product_id
where s.created_date < (select gold_signup_date as date from goldusers_signup as gu where s.userid = gu.userid)
group by s.userid 
order by userid

--9 if buying each product generates points for p1 5rs = 1point , p2 10rs = 5point , p3 5rs = 1point

with q as 
(select s.userid,s.product_id,sum(p.price) as money_spent from sales as s
join product as p on s.product_id = p.product_id
group by s.userid,s.product_id)

select r.userid,sum(r._points) as total_points from
(select q.* , case 
when q.product_id = 1  then round(q.money_spent/5)
when q.product_id = 2 then round(q.money_spent/2)
else  round(q.money_spent/5)
end as _points
from q) as r
group by r.userid

--10 first year spending , later spending in terms of  points which is 5 points = 10rs after joining as golden customer 

select q.userid,round(q.first_year_spend/2) as first_year_points, sum(q.cost) as cumm__points from
(select r.userid,r.product_id,round(r.price/2 )as cost ,first_value(r.price) over(partition by r.userid order by r.created_date) first_year_spend 
from (select s.*,p.price from sales as s 
join product as p on p.product_id = s.product_id
where s.created_date >= (select gu.gold_signup_date from goldusers_signup as gu where s.userid=gu.userid)) as r) as q group by q.userid,q.first_year_spend

--11 rank  transactions of each product by user

select q.*, rank() over(partition by userid order by total desc) as ranked
from (select r.userid,r.product_id,sum(r.price)*count(r.product_id) as total from
(select s.userid,s.product_id,p.price from sales as s
join product as p on p.product_id = s.product_id ) as r
group by s.product_id ,userid) as q

--12 rank all transactions if user is golden member and not then null

select t.*,case when gold_date is null then 'na' else rank() over(partition by t.userid order by t.created_date desc ) end as ranked from 
(select s.*,gu.gold_signup_date as gold_date from sales s 
left join goldusers_signup as gu on s.userid=gu.userid and s.created_date>=gu.gold_signup_date) as t

