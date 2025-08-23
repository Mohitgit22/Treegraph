# Write your MySQL query statement below

select product_name, year, price from Sales as S
inner join Product as P
where S.product_id = p.product_id;