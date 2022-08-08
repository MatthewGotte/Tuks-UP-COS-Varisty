<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:output method="html"/>

	<xsl:template match="/">
	    <b>Available Books</b>
	    <xsl:apply-templates select="//book">
		  	<xsl:sort select="@isbn" data-type="number"/>
		</xsl:apply-templates>

		<i>
			<br/>
			Total books available:
			<xsl:value-of select="count(/up/library/book[not(@status)])"/>
			<br/>
			Total books taken out:
			<xsl:value-of select="count(/up/library/book[@status])"/>
		</i>
    </xsl:template>

	<xsl:template match="book[not(@status)]">

		<xsl:choose>
			<xsl:when test="../@name= 'merensky'">
				<br/>
				Book 
				<xsl:value-of select="current()/@isbn"/> 
				can be found in
				<xsl:text>Merensky</xsl:text>

			</xsl:when>
			<xsl:otherwise>
				<xsl:if test="../@name = 'klinikala'">
					<xsl:text>, Klinikala</xsl:text>
				</xsl:if>
				<xsl:if test="../@name = 'music'">
					<xsl:text>, Music</xsl:text>
				</xsl:if>
			</xsl:otherwise>
		</xsl:choose>


	</xsl:template>

</xsl:stylesheet>