select * from delivery_partner;
select * from food;
select * from menu;
select * from orders_details;
select * from orders;
select * from restaurants;
select * from users

--1

select name from users where user_id not in (select user_id from orders_details group by user_id)

--2

select f.f_name , f.type ,m.average_price from food f join 
(select f_id,round(avg(price)) as average_price from menu group by f_id) m
on f.f_id = m.f_id

--3

select r.r_name , m.r_id,m.count,m.month from restaurants as r join 
(select r_id,count(r_id) as count , monthname(date) as 'month' from orders_details where monthname(date) like 'june' group by  monthname(date),r_id order by count desc limit 1) as m
on r.r_id = m.r_id

--4

with 
total_sum as 
( select r_id,monthname(date),sum(amount) sum from orders_details where monthname(date) like 'june' group by monthname(date) , r_id  order by sum desc),
average as
(select avg(sum) as mean from total_sum)
 select * from total_sum , average
where total_sum.sum > average.mean

--5

select u.name,r.r_name,f.f_name,f.type from orders_details as od 
join users as u on u.user_id = od.user_id
join restaurants as r on r.r_id = od.r_id
join orders as o on od.order_id = o.order_id
join food as f on o.f_id = f.f_id
where od.user_id = 1 and 
extract(day from od.date) between 10 and 26 and 
monthname(od.date) like 'june'

--6

select n.r_id ,count(n.visits) as total from
(select r_id,user_id,count(user_id) as visits from orders_details group by r_id,user_id 
having visits > 1
order by r_id asc) as n
join restaurants as r on n.r_id = r.r_id
group by n.r_id
order by total desc limit 1

 --7
 
with 
income as
(select monthname(date) as month , sum(amount) as revenue from orders_details 
group by monthname(date)),
temp as 
(select * ,lag(revenue,1) over() as val from income )

select month,revenue ,((revenue-val)/val)*100 as growth  from temp

--8
 
with temp as 
(select p.user_id , p.f_name ,count(p.f_name) as count from 
(select od.user_id , f.f_name from orders_details as od
join orders as o on od.order_id = o.order_id
join food as f on o.f_id = f.f_id) as p
group by p.f_name,p.user_id)

select *from temp as t1 where t1.count = (select max(count) from temp as t2 where t1.user_id = t2.user_id)


