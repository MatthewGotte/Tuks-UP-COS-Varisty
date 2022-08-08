<?xml version="1.0" encoding="UTF-8" ?>

<!-- New XSL-FO document created with EditiX XML Editor (http://www.editix.com) at Wed Jul 07 20:56:14 CAT 2021 -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
	<xsl:output method="xml" indent="yes"/>
	<xsl:template match="/">
		<fo:root>
			<fo:layout-master-set>
				<fo:simple-page-master master-name="pokedex" page-height="148mm" page-width="210mm">
					<fo:region-body margin="15mm"/>
					<fo:region-before extent="10mm" background-color="#bc6c6c"/>
					<fo:region-after extent="10mm" background-color="#bc6c6c"/>
				</fo:simple-page-master>
			</fo:layout-master-set>
			<fo:page-sequence master-reference="pokedex">
				<fo:static-content flow-name="xsl-region-before">
					<fo:block margin-left="5mm" margin-bottom="3mm" margin-top="3mm" color="white" font-weight="bold">My Minidex</fo:block>
				</fo:static-content>
				<fo:static-content flow-name="xsl-region-after">
					<fo:block margin-top="3mm" margin-bottom="3mm" margin-left="190mm" color="white">
						<xsl:text>Page </xsl:text>
						<fo:page-number/>
					</fo:block>
				</fo:static-content>
				<fo:flow flow-name="xsl-region-body">
					<fo:block>
						<xsl:for-each select="pokedex/pokemon">
							<xsl:sort select="current()/pokedex_number" data-type="number"/>
							<xsl:apply-templates select="current()"/>
						</xsl:for-each>
					</fo:block>
				</fo:flow>
			</fo:page-sequence>
		</fo:root>
	</xsl:template>
	<xsl:template match="pokemon">
		<xsl:for-each select="current()">
			<fo:block break-after="page">
				<fo:table table-layout="fixed">
					<fo:table-body>
						<fo:table-row>
							<fo:table-cell width="60mm"><!--left 1st-->
								<fo:block><!--<xsl:value-of select="current()/pokedex_number"></xsl:value-of>--><!--LEFT COLUMN TABLE = 3 x 1-->
									<fo:table table-layout="fixed">
										<table-column column-width="proportional-column-width(1)"/>
										<fo:table-body>
											<fo:table-row>
												<fo:table-cell><!--left col, first row, heading thing-->
													<fo:block font-weight="bold" color="#5a9442">
														<xsl:text>#</xsl:text>
														<xsl:value-of select="current()/pokedex_number"/>
														<xsl:text> </xsl:text>
														<xsl:value-of select="current()/species"/>
													</fo:block>
												</fo:table-cell>
											</fo:table-row>
											<fo:table-row>
												<fo:table-cell><!--left col, middle row, picture table-->
													<fo:block><!--picture 2x2 grid-->
														<fo:table table-layout="fixed">
															<table-column column-width="proportional-column-width(1)"/>
															<table-column column-width="proportional-column-width(1)"/>
															<fo:table-body>
																<fo:table-row>
																	<fo:table-cell>
																		<fo:block><!--top left picture, NORMAL-->
																			<xsl:variable name="extensiontype" select="current()/image/normal/@type"/>
																			<xsl:variable name="filename" select="current()/image/normal"/>
																			<fo:external-graphic content-height="25mm" width="25mm" src="./images/normal/front/{$filename}.{$extensiontype}"/>
																		</fo:block>
																	</fo:table-cell>
																	<fo:table-cell>
																		<fo:block><!--top right picture, NORMAL BACK-->
																			<xsl:variable name="extensiontype" select="current()/image/normal/@type"/>
																			<xsl:variable name="filename" select="current()/image/normal"/>
																			<fo:external-graphic content-height="25mm" width="25mm" src="./images/normal/back/{$filename}.{$extensiontype}"/>
																		</fo:block>
																	</fo:table-cell>
																</fo:table-row>
																<fo:table-row>
																	<fo:table-cell>
																		<fo:block><!--bottom left picture, RARE-->
																			<xsl:variable name="extensiontype" select="current()/image/normal/@type"/>
																			<xsl:variable name="filename" select="current()/image/normal"/>
																			<fo:external-graphic content-height="25mm" width="25mm" src="./images/shiny/front/{$filename}.{$extensiontype}"/>
																		</fo:block>
																	</fo:table-cell>
																	<fo:table-cell>
																		<fo:block><!--bottom right picture, RARE BACK-->
																			<xsl:variable name="extensiontype" select="current()/image/normal/@type"/>
																			<xsl:variable name="filename" select="current()/image/normal"/>
																			<fo:external-graphic content-height="25mm" width="25mm" src="./images/shiny/front/{$filename}.{$extensiontype}"/>
																		</fo:block>
																	</fo:table-cell>
																</fo:table-row>
															</fo:table-body>
														</fo:table>
													</fo:block>
												</fo:table-cell>
											</fo:table-row>
											<fo:table-row>
												<fo:table-cell><!--left col, bottom row, stats list-->
													<fo:block border-color="yellow" border-style="solid" border-width="thick" padding="2%" margin="2%">
														<xsl:text>Attack: </xsl:text>
														<xsl:value-of select="current()/base_stats/atk"/>
														<xsl:text>&#x2028;Defence: </xsl:text>
														<xsl:value-of select="current()/base_stats/def"/>
														<xsl:text>&#x2028;Sp. Attack: </xsl:text>
														<xsl:value-of select="current()/base_stats/satk"/>
														<xsl:text>&#x2028;Sp. Defence: </xsl:text>
														<xsl:value-of select="current()/base_stats/sdef"/>
														<xsl:text>&#x2028;Speed: </xsl:text>
														<xsl:value-of select="current()/base_stats/spd"/>
														<xsl:text>&#x2028;Average stats: </xsl:text>
														<xsl:value-of select="sum(current()/base_stats/*)"/>
													</fo:block>
												</fo:table-cell>
											</fo:table-row>
										</fo:table-body>
									</fo:table>
								</fo:block>
							</fo:table-cell>
							<fo:table-cell><!--right 1st-->
								<fo:block><!--RIGHT COLUMN TABLE = 4 x 1-->
									<fo:table table-layout="fixed">
										<table-column column-width="proportional-column-width(1)"/>
										<fo:table-body>
											<fo:table-row>
												<fo:table-cell>
													<fo:block border-color="purple" border-style="solid" border-width="thick" padding="2%" margin="2%"><!--Evolution Chain-->
														<fo:table table-layout="fixed">
															<table-column column-width="proportional-column-width(1)"/>
															<fo:table-body>
																<fo:table-row>
																	<fo:table-cell>
																		<fo:block font-weight="bold">Evolution Chain:</fo:block>
																	</fo:table-cell>
																</fo:table-row>
																<fo:table-row>
																	<fo:table-cell>
																		<fo:block><!--<xsl:value-of select="current()/pokedex_number"></xsl:value-of>-->
																		<xsl:variable name="iddex" select="current()//pokedex_number"></xsl:variable>
																			<xsl:choose>
																				<xsl:when test="current()/evolution_chain/evolution">
																				<!--Print evolution-->
																				
																						<fo:table table-layout="fixed">
																							<fo:table-body>
																								<fo:table-row>
																									<xsl:for-each select="current()/evolution_chain/evolution/evolution_stage">
																										<fo:table-cell>
																											<fo:block>
																												<xsl:variable name="filename" select="current()"/>
																												
																												<xsl:choose>
																													<xsl:when test="current &lt; 100">
																														<fo:external-graphic content-height="25mm" width="25mm" src="./images/normal/front/{$filename}.png"/>
																													</xsl:when>
																													<xsl:otherwise>
																														<fo:external-graphic content-height="25mm" width="25mm" src="./images/normal/front/{$iddex}.png"/>
																													</xsl:otherwise>
																												</xsl:choose>
																												
																												<fo:external-graphic content-height="10mm" width="10mm" src="./images/to.png"/>
																												
																											</fo:block>
																										</fo:table-cell>
																									</xsl:for-each>
																									
																								</fo:table-row>
																							</fo:table-body>
																						</fo:table>
																				</xsl:when>
																				<xsl:otherwise>
																				<!--No evolution-->
																					<fo:external-graphic content-height="25mm" width="25mm" src="./images/000.png"/>
																				</xsl:otherwise>
																			</xsl:choose>
																		</fo:block>
																	</fo:table-cell>
																</fo:table-row>
															</fo:table-body>
														</fo:table>
													</fo:block>
												</fo:table-cell>
											</fo:table-row>
											<fo:table-row>
												<fo:table-cell>
													<fo:block border-color="blue" border-style="solid" border-width="thick" padding="2%" margin="2%"><!--Type-->
														<fo:table table-layout="fixed">
															<fo:table-body>
																<fo:table-row>
																	<fo:table-cell width="20mm">
																		<fo:block font-weight="bold">Types: </fo:block>
																	</fo:table-cell>
																	<fo:table-cell>
																		<fo:block>
																			<xsl:for-each select="current()/types/*">
																				<xsl:if test="position() &gt; 1"> | </xsl:if>
																				<xsl:value-of select="current()"/>
																			</xsl:for-each>
																		</fo:block>
																	</fo:table-cell>
																</fo:table-row>
															</fo:table-body>
														</fo:table>
													</fo:block>
												</fo:table-cell>
											</fo:table-row>
											<fo:table-row>
												<fo:table-cell width="20mm">
													<fo:block border-color="orange" border-style="solid" border-width="thick" padding="2%" margin="2%"><!--Height, Weight, size-->
														<fo:table table-layout="fixed">
															<fo:table-body>
																<fo:table-row>
																	<fo:table-cell width="20mm">
																		<fo:block font-weight="bold">Height: </fo:block>
																	</fo:table-cell>
																	<fo:table-cell>
																		<fo:block>
																			<xsl:for-each select="current()/size/height/*">
																				<xsl:value-of select="current()"/>
																				<xsl:text> </xsl:text>
																				<xsl:value-of select="name(current())"/>
																				<xsl:text> </xsl:text>
																			</xsl:for-each>
																		</fo:block>
																	</fo:table-cell>
																</fo:table-row>
																<fo:table-row>
																	<fo:table-cell>
																		<fo:block font-weight="bold">Weight: </fo:block>
																	</fo:table-cell>
																	<fo:table-cell>
																		<fo:block>
																			<xsl:for-each select="current()/size/weight/*">
																				<xsl:if test="name(current()) != 'weight_class'">
																					<xsl:value-of select="current()"/>
																					<xsl:text> </xsl:text>
																					<xsl:value-of select="name(current())"/>
																					<xsl:text> </xsl:text>
																				</xsl:if>
																			</xsl:for-each>
																		</fo:block>
																	</fo:table-cell>
																</fo:table-row>
																<fo:table-row>
																	<fo:table-cell>
																		<fo:block font-weight="bold">Size: </fo:block>
																	</fo:table-cell>
																	<fo:table-cell>
																		<fo:block>
																			<xsl:variable name="upper" select="current()/size/size_category"/>
																			<xsl:variable name="lower" select="translate($upper,'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')"/>
																			<xsl:value-of select="$lower"/>
																		</fo:block>
																	</fo:table-cell>
																</fo:table-row>
															</fo:table-body>
														</fo:table>
													</fo:block>
												</fo:table-cell>
											</fo:table-row>
											<fo:table-row>
												<fo:table-cell>
													<fo:block border-color="red" border-style="solid" border-width="thick" padding="2%" margin="2%"><!--Capture rate-->
														<fo:table table-layout="fixed">
															<fo:table-body>
																<fo:table-row>
																	<fo:table-cell width="35mm">
																		<fo:block>Capture rate</fo:block>
																	</fo:table-cell>
																	<fo:table-cell width="10mm">
																		<fo:block font-weight="bold">
																			<xsl:value-of select="current()/capture_rate"/>
																		</fo:block>
																	</fo:table-cell>
																	<fo:table-cell width="15mm">
																		<fo:block font-weight="bold">
																			<xsl:value-of select="current()/exp_drop"/>
																		</fo:block>
																	</fo:table-cell>
																	<fo:table-cell width="50mm">
																		<fo:block>Exp drop</fo:block>
																	</fo:table-cell>
																</fo:table-row>
															</fo:table-body>
														</fo:table>
													</fo:block>
												</fo:table-cell>
											</fo:table-row>
										</fo:table-body>
									</fo:table>
								</fo:block>
							</fo:table-cell>
						</fo:table-row>
					</fo:table-body>
				</fo:table>
			</fo:block>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
