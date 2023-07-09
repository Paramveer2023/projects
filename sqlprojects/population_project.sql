
select * from data1;
select * from data2;

select count(*) from data1;
select count(*) from data2;

-- data for jharkhand and bihar
select * from data1 where State in ("Bihar","Jharkhand")

-- total population and avg_growth , avg_sex_ratio, avg_literacy-rate

select sum(Population) from data2;

select state,round(avg(growth)*100 ) as avg_growth,round(avg(sex_ratio)) as avg_sex_ratio ,
round(avg(literacy)) as avg_literacy
from data1 group by state order by avg_growth;

--- states with highest literacy rate based on growth rate 

select state,round(avg(literacy)) as avg_literacy ,round(avg(growth)*100 ) as avg_growth 
from data1 group by state having round(avg(growth)*100 ) limit 5

select state,round(avg(literacy)) as avg_literacy ,round(avg(growth)*100 ) as avg_growth 
from data1 group by state having round(avg(growth)*100 ) order by avg_growth desc limit 5

---to find both data from above in single table

with 
temp1 as (
select state,round(avg(literacy)) as avg_literacy ,round(avg(growth)*100 ) as avg_growth 
from data1 group by state having round(avg(growth)*100 ) limit 5
),
temp2 as (
select state,round(avg(literacy)) as avg_literacy ,round(avg(growth)*100 ) as avg_growth 
from data1 group by state having round(avg(growth)*100 ) order by avg_growth desc limit 5
			)
select * from temp1
union 
select * from temp2

--or

drop table if exists temp2;
create table temp2(
state varchar(255),
avg_literacy int,
avg_growth int);
insert into temp2 select state,round(avg(literacy)) as avg_literacy ,round(avg(growth)*100 ) as avg_growth 
from data1 group by state having round(avg(growth)*100 ) order by avg_growth desc limit 5;

select * from temp1
union
select * from temp2;

drop table temp1,temp2;

-- select states name starting with a

select * from data1 where state like "a%";
select * from data1 where state like "a%h";

--joining both the table 

with
temp as (
select data1.*,data2.population from data1 
join  data2 
on data1.district = data2.district
 ),
temp2 as (
select *,(population/1000*sex_ratio) as No_females from temp
)

select *,(population - No_females) as No_males  from temp2

--or

select u.*,(u.population - u.No_females) as No_males from (
select t.*,(t.population/1000*t.sex_ratio) as No_females from (select data1.*,data2.population from data1 
join  data2 
on data1.district = data2.district) as t ) as u

--literate people 

select p.state, p.literate_population ,round((p.population-p.literate_population)) as iliterate_population from
(select data1.state,round(sum(data1.literacy*data2.population/100)) as literate_population ,sum(data2.population) as population
from data1 join  data2 
on data1.district = data2.district group by state) as p

--population in previuos year and next year

select d.district,d.state,round(d.population/d.growth_rate) as prev_year_pop, d.population as pres_year_pop,
round(d.population*d.growth_rate) as next_year_pop from
(select d1.*,d2.population,(1+d1.growth) as growth_rate
from data1 d1 join  data2 d2
on d1.district = d2.district) as d

--top 3  districts with highest literacy_rate,population from each state

select r.district,r.state,r.literacy from
(select q.literacy,q.district,q.state,rank() over(partition by q.state order by q.literacy desc) as ranked
from (select d1.*,d2.population
from data1 d1 join  data2 d2
on d1.district = d2.district) as q) as r
where r.ranked<4



 