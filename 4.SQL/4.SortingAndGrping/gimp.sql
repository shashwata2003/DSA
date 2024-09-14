/*Table: Customer

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| customer_id | int     |
| product_key | int     |
+-------------+---------+
This table may contain duplicates rows. 
customer_id is not NULL.
product_key is a foreign key (reference column) to Product table.
 

Table: Product

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_key | int     |
+-------------+---------+
product_key is the primary key (column with unique values) for this table.
 

Write a solution to report the customer ids from the Customer table that bought all the products in the Product table.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Customer table:
+-------------+-------------+
| customer_id | product_key |
+-------------+-------------+
| 1           | 5           |
| 2           | 6           |
| 3           | 5           |
| 3           | 6           |
| 1           | 6           |
+-------------+-------------+
Product table:
+-------------+
| product_key |
+-------------+
| 5           |
| 6           |
+-------------+
Output: 
+-------------+
| customer_id |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: 
The customers who bought all the products (5 and 6) are customers with IDs 1 and 3.
*/

/*
ProductCount: A CTE (Common Table Expression) to count the total number of products in the Product table.
CustomerProductCount: A CTE to count how many distinct products each customer has purchased.
JOIN ProductCount: This ensures that we only select customers whose distinct product purchases match the total number of products available.

Steps:
Count the total number of unique products from the Product table.
For each customer, count the number of distinct products they have purchased from the Customer table.
Compare the two counts: if a customer has bought the same number of products as the total number of unique products, then they have bought all the products.
*/

WITH ProductCount AS (
    SELECT COUNT(*) AS total_products
    FROM Product
),
CustomerProductCount AS (
    SELECT customer_id, COUNT(DISTINCT product_key) AS purchased_products
    FROM Customer
    GROUP BY customer_id
)
SELECT c.customer_id
FROM CustomerProductCount c
JOIN ProductCount p
ON c.purchased_products = p.total_products;
