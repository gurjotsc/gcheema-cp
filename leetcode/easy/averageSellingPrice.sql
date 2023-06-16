# Write your MySQL query statement below
SELECT p.product_id, round(sum(price*units)/sum(units), 2) AS average_price
FROM Prices p
JOIN UnitsSold u ON p.product_id=u.product_id
WHERE u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id