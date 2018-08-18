SELECT wt1.Id
FROM Weather wt1, Weather wt2
WHERE wt1.Temperature > wt2.Temperature
AND DATEDIFF(wt1.RecordDate, wt2.RecordDate) = 1