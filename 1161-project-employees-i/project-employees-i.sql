# Write your MySQL query statement below

select project_id, round(avg(q.experience_years), 2) as average_years from Project as p
join Employee as q 
on p.employee_id = q.employee_id
group by p.project_id;