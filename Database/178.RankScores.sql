ELECT a.`Score`,  ((SELECT COUNT(DISTINCT b.Score) FROM `Scores` b WHERE b.Score > a.Score) + 1) AS Rank
FROM `Scores` a ORDER BY Rank;
