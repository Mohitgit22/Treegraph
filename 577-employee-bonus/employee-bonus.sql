# Write your MySQL query statement below

select name, bonus from Employee as E
left join Bonus as B
on E.empId = b.empId
where B.bonus < 1000 or B.bonus is NULL;