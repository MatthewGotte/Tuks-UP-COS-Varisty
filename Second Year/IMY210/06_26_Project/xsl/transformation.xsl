<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:output method="html"/>
    

    <xsl:template match="/">

        <xsl:choose>
            <xsl:when test="//product/name">
                <xsl:call-template name="product"/>	
            </xsl:when>
            <xsl:otherwise>
                <xsl:choose>
                    <xsl:when test="//index/category">
                        <xsl:call-template name="categories"/>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:call-template name="productindex"/>
                    </xsl:otherwise>
                </xsl:choose>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>

    <xsl:template name="categories">
        <link rel="stylesheet" href="../css_js/style.css"/>
        <a href="../php/index.php">Home</a>
        <!--categories index-->   
        <h1 class="heading"><u>Categories</u></h1>
        <xsl:for-each select="/index/*">
            <xsl:variable name="link" select="current()"/>
            <p class="navlink"><a href="{$link}/index.xml"><xsl:value-of select="current()"/></a></p>
            <br />
        </xsl:for-each>   
    </xsl:template>

    <xsl:template name="product">
        <link rel="stylesheet" href="../../css_js/style.css"/>
        <a href="./index.xml">Back</a>
        <div class="centerhead">
        <h1 class="flexcenter heading"><u><xsl:value-of select="//product/name"/></u></h1>
        </div>
        <xsl:variable name="imglink" select="//product/image"/>
        <img class="propic" src="./Images/{$imglink}" alt="{$imglink}"/>
    
        <div class="shifter">
            <xsl:for-each select="/product/*">
            <p><xsl:value-of select="name(current())"/> :    <xsl:value-of select="current()"/></p>
            </xsl:for-each>
        </div>

        
        <!--product index-->        
        
    </xsl:template>

    <xsl:template name="productindex">
        <link rel="stylesheet" href="../../css_js/style.css"/>
        <a href="../index.xml">Back</a>
        <!--category index-->        
        <h1 class="heading"><u>Products</u></h1>
        <xsl:for-each select="/index/*">
            <xsl:variable name="link" select="current()/@id"/>
            <p class="navlink"><a href="{$link}.xml"><xsl:value-of select="current()"/></a></p>
            <br />
        </xsl:for-each> 
    </xsl:template>

</xsl:stylesheet>