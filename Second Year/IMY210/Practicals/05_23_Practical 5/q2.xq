(:Matthew Gotte - u20734621:)
<list>{
  for $cd in doc("cd.xml")/CATALOG/CD
  let $year := $cd/YEAR
  where $year <= 1987
  let $title := $cd/TITLE
  let $artist := $cd/ARTIST
  let $company := $cd/COMPANY
  let $country := $cd/COUNTRY
  return <li>{data($title)} by {data($artist)} - {data($company)}, {data($country)}</li>
}</list>