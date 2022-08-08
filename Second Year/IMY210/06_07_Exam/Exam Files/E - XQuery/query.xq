(:Matthew Gotte - u20734621:)
<html>
<head/>
<body>
{
    let $one := doc("query-xml-one")
    let $two := doc("query-xml-two")
    let $genrelist := $one/catalog/book/genre
    for $genre in distinct-values($one/catalog/book/genre)
    order by $genre
    return 
    <group cost="{$genre}" count="{count(index-of($one//genre, $genre))}">
    {
       let $books := $one/catalog/book
       for $book in $books
       where $book/genre = $genre
       for $book_2 in $two/catalog/book
       where data($book_2/@id) = data($book/@id)
       order by $book_2/(publish_date)
       return <item>"{data($book/title)}" by {data($book/author)} at ${data($book_2/price)}</item>
    }
    </group>
}
</body>
</html>