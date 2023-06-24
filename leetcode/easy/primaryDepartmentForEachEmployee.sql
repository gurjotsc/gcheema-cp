# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE (employee_id, primary_flag) IN
(
  SELECT employee_id, MAX(primary_flag)
  FROM Employee
  GROUP BY employee_id
)