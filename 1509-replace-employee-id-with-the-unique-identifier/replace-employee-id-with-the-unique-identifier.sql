# Write your MySQL query statement below

SELECT unique_id, name FROM employees LEFT JOIN EmployeeUNI on employees.id = EmployeeUNI.id;