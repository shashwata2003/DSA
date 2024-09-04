/**/
/*
Using self join:
w1 is the current date and w2 the previous data
we created w1 and w2 to compare in the same table 
Date_sub substracts the w1 date with the interval of 1 day and it should be equal to previous date 

*/

select w1.id from Weather w1 join Weather w2 
on date_sub(w1.recordDate, interval 1 day) = w2.recordDate 
where w1.temperature > w2.temperature  