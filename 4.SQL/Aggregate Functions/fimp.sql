/*
Table: Transactions

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| country       | varchar |
| state         | enum    |
| amount        | int     |
| trans_date    | date    |
+---------------+---------+
id is the primary key of this table.
The table has information about incoming transactions.
The state column is an enum of type ["approved", "declined"].
 

Write an SQL query to find for each month and country, the number of transactions and their total amount, the number of approved transactions and their total amount.

Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
Transactions table:
+------+---------+----------+--------+------------+
| id   | country | state    | amount | trans_date |
+------+---------+----------+--------+------------+
| 121  | US      | approved | 1000   | 2018-12-18 |
| 122  | US      | declined | 2000   | 2018-12-19 |
| 123  | US      | approved | 2000   | 2019-01-01 |
| 124  | DE      | approved | 2000   | 2019-01-07 |
+------+---------+----------+--------+------------+
Output: 
+----------+---------+-------------+----------------+--------------------+-----------------------+
| month    | country | trans_count | approved_count | trans_total_amount | approved_total_amount |
+----------+---------+-------------+----------------+--------------------+-----------------------+
| 2018-12  | US      | 2           | 1              | 3000               | 1000                  |
| 2019-01  | US      | 1           | 1              | 2000               | 2000                  |
| 2019-01  | DE      | 1           | 1              | 2000               | 2000                  |
+----------+---------+-------------+----------------+--------------------+-----------------------+
*/

/*
Now we form the solution column by column, starting from month.
As the month column contains only a part (year and month) from trans_date column in Transactions, we use SUBSTR() function to select a substring of trans_date starting from index 1 and going upto 7th index: SUBSTR(trans_date,1,7) as month.
We modify the select statement as
SELECT SUBSTR(trans_date,1,7) as month, country, __ as trans_count, __ as approved_count, ___ as trans_total_amount,___ as approved_total_amount
FROM Transactions

Now, we go for trans_count column (as country column is as it is taken from table Transactions), looking at the result table, we need to count the number of transections per month in a country so, we count transaction ids and GROUP them by month and country.
The code will look like this now
SELECT SUBSTR(trans_date,1,7) as month, country, count(id) as trans_count, __ as approved_count, ___ as trans_total_amount,___ as approved_total_amount
FROM Transactions
GROUP BY month, country

Now for next approved_count column, we need to check if the state of transection is "approved" if yes then we count else we don't. For this here we used CASE statement along with SUM() function as follows:
SUM(CASE WHEN state = 'approved' then 1 else 0 END).
Lastly, modify the select statement by adding:
SUM(CASE WHEN state = 'approved' then 1 else 0 END) as approved_count

Now for trans_total_amount, as we have already grouped transactions based on month and country so, we can directly write trans_total_amount column as SUM(amount).
Now updated select statement will look like this:
SELECT SUBSTR(trans_date,1,7) as month, country, count(id) as trans_count, SUM(CASE WHEN state = 'approved' then 1 else 0 END) as approved_count, SUM(amount) as trans_total_amount, ___ as approved_total_amount
FROM Transactions
GROUP BY month, country

As we wrote the condition for approved_count column similarly, we
can write for approved_total_amount. The only difference is instead of adding 1, in case the state = 'approved', we add transaction amount: SUM(CASE WHEN state = 'approved' then amount else 0 END).

Thus the final code becomes
SELECT SUBSTR(trans_date,1,7) as month, country, count(id) as trans_count, SUM(CASE WHEN state = 'approved' then 1 else 0 END) as approved_count, SUM(amount) as trans_total_amount, SUM(CASE WHEN state = 'approved' then amount else 0 END) as approved_total_amount
FROM Transactions
GROUP BY month, country
*/
SELECT 
    SUBSTR(trans_date, 1, 7) AS month,
    country,
    COUNT(id) AS trans_count,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
FROM 
    Transactions
GROUP BY 
    month, country;
