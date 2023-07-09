select * from album;
select * from artist;
select * from customer;
select * from employee;
select * from genre;
select * from invoice;
select * from invoice_line;
select * from media_type;
select * from playlist;
select * from playlist_track;
select * from track;

--1 senior most employyee by job title
with tempo as 
(select n.*,row_number() over(partition by n.title order by n.age desc) as num
from (select employee_id ,title, first_name||' '||last_name as name,
(2023 - extract(year from birthdate)) as age
from employee) as n)
select tempo.* from tempo where tempo.num = 1

--2 countries with most invoices

select billing_country,count(invoice_id) as counting 
from invoice group by billing_country order by counting desc
limit 1

--3 best city for performance

select billing_city,sum(total) as total_ 
from invoice group by billing_city order by total_ desc
limit 1

--4 best customer

select c.customer_id,c.first_name||' '||c.last_name as name,
i.invoice_id,l.quantity*l.unit_price as price
from customer as c 
join invoice as i on i.customer_id = c.customer_id
join invoice_line as l on i.invoice_id = l.invoice_id
order by price desc limit 1

select c.customer_id,c.first_name||' '||c.last_name as name,
sum(i.total) as total from customer 
as c join invoice as i on i.customer_id = c.customer_id
group by c.customer_id order by total desc limit 1 

--5 return name and email detail

select c.first_name||' '||c.last_name as name,c.email
from track as t
join genre as g on t.genre_id = t.genre_id 
join invoice_line as l on t.track_id = l.track_id
join invoice as i on l.invoice_id = i.invoice_id
join customer as c on c.customer_id = i.invoice_id
where g.name like 'Rock'

--6 artist with max rock albums

select ar.name,count(ab.album_id) as counted
from track as t
join genre as g on t.genre_id = t.genre_id 
join album as ab on t.album_id = ab.album_id
join artist as ar on ab.artist_id = ar.artist_id
where g.name like 'Rock'
group by ar.name 
order by counted desc limit 10

--7 songs with length more than avg length

select name , milliseconds
from track 
where milliseconds > (select avg(milliseconds) from track)
order by milliseconds desc

--8 

select c.first_name||' '||c.last_name as name,ar.name,sum(i.total)
from track as t
join invoice_line as l on t.track_id = l.track_id
join invoice as i on l.invoice_id = i.invoice_id
join customer as c on c.customer_id = i.invoice_id
join album as ab on t.album_id = ab.album_id
join artist as ar on  ab.artist_id = ar.artist_id
group by ar.name,c.customer_id

--9 country with most popular genre

select te.country,te.naam ,sum(te.totaled)
from (
	select c.country,g.name as naam,(l.quantity*l.unit_price) as totaled,ar.name
	from track as t
	join genre as g on t.genre_id = t.genre_id 
	join invoice_line as l on t.track_id = l.track_id
	join invoice as i on l.invoice_id = i.invoice_id
	join customer as c on c.customer_id = i.invoice_id
	join album as ab on t.album_id = ab.album_id
	join artist as ar on  ab.artist_id = ar.artist_id
	) as te group by te.country,te.naam 

	
--10	