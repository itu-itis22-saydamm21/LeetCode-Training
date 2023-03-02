SELECT USERS.user_id AS buyer_id,
USERS.join_date AS join_date, 
COUNT(ORDERS.buyer_id) AS orders_in_2019 
FROM USERS
LEFT JOIN ORDERS 
ON 
USERS.user_id = ORDERS.buyer_id 
AND 
YEAR(ORDERS.order_date) = '2019'
GROUP BY USERS.user_id

