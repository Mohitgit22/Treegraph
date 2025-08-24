# Write your MySQL query statement below

select q.query_name, 
round(sum(q.rating / q.position) / count(*) , 2) as quality,
round(SUM(CASE WHEN q.rating < 3 THEN 1 ELSE 0 END) * 100.0/count(*), 2) as poor_query_percentage
from Queries as q
group by q.query_name;

