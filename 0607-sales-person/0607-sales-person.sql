select name
from SalesPerson s
left join (
    select o.sales_id
    from Company c
    left join Orders o
    on c.com_id=o.com_id
    where c.name="RED"
) as b
on s.sales_id=b.sales_id
where b.sales_id is null