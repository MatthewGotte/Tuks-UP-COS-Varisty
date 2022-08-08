(:Matthew Gotte - u20734621:)
<totalcost>{
  round(sum(
  for $cd in doc("cd.xml")/CATALOG/CD
  let $price := $cd/PRICE
  return $price
))}</totalcost>