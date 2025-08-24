# Write your MySQL query statement below

select P.product_id , round(ifnull(sum(P.price*Q.units)/ sum(Q.units), 0), 2) as average_price from Prices as P 
left join UnitsSold as Q
on P.Product_id = Q.Product_id
AND Q.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY P.product_id;