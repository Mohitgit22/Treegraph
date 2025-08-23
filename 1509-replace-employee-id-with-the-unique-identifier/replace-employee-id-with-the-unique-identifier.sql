# Write your MySQL query statement below

select unique_id, name from Employees as E
left join EmployeeUNI as P
on E.id = P.id;