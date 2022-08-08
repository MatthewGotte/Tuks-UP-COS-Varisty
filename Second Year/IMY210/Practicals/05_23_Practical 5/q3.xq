(:Matthew Gotte - u20734621:)
<HTML>
<BODY>

<TOTAL>
{
  let $total := count(doc("cd.xml")/CATALOG/CD)
  return $total
}
</TOTAL>

<ABOVE>
    <COUNT>
    {data(
      let $count := count(doc("cd.xml")/CATALOG/CD/PRICE[text() > 9])
      return $count
    )}
    </COUNT>
    {
    for $cd in doc("cd.xml")/CATALOG/CD
    where $cd/PRICE[text() > 9]
    order by $cd/COUNTRY
    let $temp := $cd/COUNTRY
    order by $temp/TITLE
    return $cd/TITLE    
    }
</ABOVE>

<BELOW>
    <COUNT>
    {data(
      let $count := count(doc("cd.xml")/CATALOG/CD/PRICE[text() < 9])
      return $count
    )}
    </COUNT>
    {
    for $cd in doc("cd.xml")/CATALOG/CD
    where $cd/PRICE[text() < 9]
    order by $cd/COUNTRY
    let $temp := $cd/COUNTRY
    order by $temp/TITLE
    return $cd/TITLE    
    }
</BELOW>

</BODY>
</HTML>