-- # Write your MySQL query statement below

-- select p.contest_id , round(count(p.user_id) * 100 / count(q.user_id), 2) as percentage from Register as p
-- join Users as q
-- on p.user_id = q.user_id
-- group by p.contest_id
-- order by percertage desc, ;


SELECT 
    r.contest_id,
    ROUND(COUNT(DISTINCT r.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;
