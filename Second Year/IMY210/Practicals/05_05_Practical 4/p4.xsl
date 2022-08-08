<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
	<xsl:output method="xml" indent="yes"/>
	<xsl:template match="/">
		<fo:root>
			<fo:layout-master-set>
				<fo:simple-page-master master-name="cover" page-height="80mm" page-width="210mm">
					<fo:region-body/>
				</fo:simple-page-master>
				<fo:simple-page-master master-name="content" page-height="80mm" page-width="210mm">
					<fo:region-body margin="10mm"/>
					<fo:region-before extent="10mm" background-color="#aeddf6"/>
					<fo:region-after extent="10mm" background-color="#68ba4a"/>
					<fo:region-start extent="10mm" background-color="#aeddf6"/>
					<fo:region-end extent="10mm" background-color="#68ba4a"/><!-- Complete this declareation by adding the margin, extent and background-color where nessessary -->
				</fo:simple-page-master>
			</fo:layout-master-set>
			<fo:page-sequence master-reference="cover" force-page-count="no-force">
				<fo:flow flow-name="xsl-region-body">
					<fo:block>
						<xsl:variable name="logo" select="animals/@siteLogo"/>
						<fo:external-graphic content-height="80mm" width="210mm" src="images/{$logo}"/>
					</fo:block>
				</fo:flow><!--For the cover page create a single flow and reference the flow to your body region declared in the simple-page-master--><!-- Inside your flow create a block In this block align the content to center, and add the logo image--><!--You can alter the height of the images to how you see fit-->
			</fo:page-sequence>
			<fo:page-sequence master-reference="content" initial-page-number="1">
				<fo:static-content flow-name="xsl-region-before">
					<fo:block margin-left="5mm" margin-bottom="3mm" margin-top="3mm" color="white" font-weight="bold"><xsl:value-of select="animals/@publication"/></fo:block>
				</fo:static-content>
				<fo:static-content flow-name="xsl-region-after">
					<fo:block margin-top="3mm" margin-bottom="3mm" margin-left="180mm" color="white">
						<fo:page-number/>
					</fo:block>
				</fo:static-content>
				<fo:flow flow-name="xsl-region-body">
					<fo:block>
						<fo:table margin-left="0.5mm" margin-top="0.5mm">
							<fo:table-column column-width="60mm"/>
							<fo:table-column column-width="150mm"/>
							<fo:table-body>
								<xsl:for-each select="/animals/animal">
									<fo:table-row>
										<fo:table-cell width="50mm">
											<fo:block>
												<xsl:variable name="img" select="current()/@image"/>
												<fo:external-graphic border="1mm solid grey" text-align="center" content-height="50mm" src="images/{$img}"/>
											</fo:block>
										</fo:table-cell>
										<fo:table-cell width="130mm">
											<fo:block break-after="page">
												<fo:block font-weight="bold">
													<xsl:value-of select="name"/>
												</fo:block>
												<fo:block font-weight="bold" color="#aeddf6">
													<xsl:value-of select="sciName"/>
												</fo:block>
												<fo:block background-color="#aeddf6" padding="3mm">
													<xsl:value-of select="abstract"/>
													<fo:block font-size="9px">
														Read more at <xsl:value-of select="abstract/@more"/>
													</fo:block>
												</fo:block>
												<fo:block margin-top="1mm">
													Tags:
													<xsl:variable name="temp" select="count(current()/tags)"/>
													<xsl:for-each select="current()/tags/tag">
														<xsl:if test="position() > 0">
															<xsl:if test="not(position() = $temp)"> / </xsl:if>
														</xsl:if>
														<xsl:value-of select="current()"/>
													</xsl:for-each>
												</fo:block>
											</fo:block>
										</fo:table-cell>
									</fo:table-row>
								</xsl:for-each>
							</fo:table-body>
						</fo:table>
					</fo:block>
				</fo:flow>
			</fo:page-sequence>
		</fo:root>
	</xsl:template>
</xsl:stylesheet>
