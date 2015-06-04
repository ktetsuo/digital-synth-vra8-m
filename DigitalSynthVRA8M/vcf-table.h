#pragma once

const uint8_t g_vcf_lpf_table_q_2_sqrt_2[] = {
   +10,   +0, -127,  +10,   +0, -127,  +11,   +0, -127,  +12,   +0, -127,
   +13,   +0, -127,  +14,   +0, -127,  +14,   +0, -127,  +15,   +0, -127,
   +16,   +0, -127,  +18,   +0, -127,  +19,   +0, -127,  +20,   +0, -127,
   +21,   +0, -127,  +23,   +0, -126,  +24,   +0, -126,  +26,   +0, -126,
   +27,   +0, -126,  +29,   +0, -126,  +31,   +0, -126,  +33,   +0, -126,
   +36,   +0, -126,  +38,   +0, -126,  +40,   +0, -126,  +43,   +0, -126,
   +46,   +0, -125,  +49,   +0, -125,  +52,   +0, -125,  +56,   +0, -125,
   +60,   +0, -125,  +63,   +0, -125,  +68,   +0, -125,  +72,   +0, -124,
   +77,   +0, -124,  +82,   +0, -124,  +87,   +0, -124,  +93,   +0, -124,
   +99,   +0, -123, +106,   +0, -123, +113,   +0, -123, +120,   +0, -123,
  +128,   +0, -123, +137,   +0, -122, +146,   +0, -122, +155,   +0, -122,
  +166,   +0, -121, +177,   +0, -121, +188,   +0, -121, +200,   +0, -120,
  +214,   +0, -120, +228,   +0, -120, +242,   +0, -119,   +2,   +1, -119,
   +19,   +1, -119,  +37,   +1, -118,  +56,   +1, -118,  +76,   +1, -117,
   +98,   +1, -117, +121,   +1, -116, +145,   +1, -115, +171,   +1, -115,
  +199,   +1, -114, +228,   +1, -113,   +4,   +2, -113,  +37,   +2, -112,
   +72,   +2, -111, +110,   +2, -110, +149,   +2, -110, +192,   +2, -109,
  +236,   +2, -108,  +28,   +3, -107,  +79,   +3, -106, +132,   +3, -105,
  +189,   +3, -103, +249,   +3, -102,  +57,   +4, -101, +125,   +4, -100,
  +197,   +4,  -98,  +17,   +5,  -97,  +98,   +5,  -95, +184,   +5,  -93,
   +18,   +6,  -92, +114,   +6,  -90, +215,   +6,  -88,  +66,   +7,  -86,
  +180,   +7,  -84,  +43,   +8,  -82, +170,   +8,  -79,  +47,   +9,  -77,
  +189,   +9,  -74,  +81,  +10,  -72, +238,  +10,  -69, +148,  +11,  -66,
   +66,  +12,  -63, +250,  +12,  -60, +187,  +13,  -57, +134,  +14,  -53,
   +92,  +15,  -50,  +60,  +16,  -46,  +40,  +17,  -42,  +32,  +18,  -38,
   +35,  +19,  -33,  +51,  +20,  -29,  +79,  +21,  -24, +121,  +22,  -20,
  +176,  +23,  -15, +245,  +24,   -9,  +72,  +26,   -4, +169,  +27,   +1,
   +24,  +29,   +7, +149,  +30,  +13,  +33,  +32,  +19, +188,  +33,  +25,
  +100,  +35,  +32,  +25,  +37,  +38, +220,  +38,  +45, +171,  +40,  +51,
  +133,  +42,  +58, +105,  +44,  +65,  +84,  +46,  +72,  +70,  +48,  +79,
   +58,  +50,  +86,  +47,  +52,  +92,  +31,  +54,  +99,   +5,  +56, +105,
  +221,  +57, +111, +158,  +59, +116,  +64,  +61, +121, +186,  +62, +125,
};

const uint8_t g_vcf_lpf_table_q_1_sqrt_2[] = {
   +10,   +0, -126,  +10,   +0, -126,  +11,   +0, -126,  +12,   +0, -126,
   +13,   +0, -126,  +13,   +0, -126,  +14,   +0, -126,  +15,   +0, -126,
   +16,   +0, -125,  +17,   +0, -125,  +18,   +0, -125,  +20,   +0, -125,
   +21,   +0, -125,  +22,   +0, -125,  +24,   +0, -125,  +25,   +0, -125,
   +27,   +0, -124,  +29,   +0, -124,  +31,   +0, -124,  +33,   +0, -124,
   +35,   +0, -124,  +37,   +0, -124,  +40,   +0, -123,  +42,   +0, -123,
   +45,   +0, -123,  +48,   +0, -123,  +51,   +0, -123,  +55,   +0, -123,
   +58,   +0, -122,  +62,   +0, -122,  +66,   +0, -122,  +71,   +0, -122,
   +75,   +0, -121,  +80,   +0, -121,  +85,   +0, -121,  +91,   +0, -121,
   +97,   +0, -120, +103,   +0, -120, +110,   +0, -120, +117,   +0, -119,
  +125,   +0, -119, +133,   +0, -119, +141,   +0, -118, +150,   +0, -118,
  +160,   +0, -117, +170,   +0, -117, +181,   +0, -117, +193,   +0, -116,
  +205,   +0, -116, +219,   +0, -115, +233,   +0, -115, +248,   +0, -114,
    +7,   +1, -114,  +24,   +1, -113,  +42,   +1, -112,  +61,   +1, -112,
   +81,   +1, -111, +103,   +1, -110, +125,   +1, -110, +149,   +1, -109,
  +175,   +1, -108, +202,   +1, -107, +231,   +1, -106,   +5,   +2, -106,
   +37,   +2, -105,  +71,   +2, -104, +108,   +2, -103, +146,   +2, -102,
  +187,   +2, -101, +230,   +2,  -99,  +19,   +3,  -98,  +68,   +3,  -97,
  +119,   +3,  -96, +173,   +3,  -95, +230,   +3,  -93,  +34,   +4,  -92,
   +98,   +4,  -90, +166,   +4,  -89, +237,   +4,  -87,  +56,   +5,  -85,
  +136,   +5,  -84, +219,   +5,  -82,  +52,   +6,  -80, +145,   +6,  -78,
  +244,   +6,  -76,  +92,   +7,  -74, +201,   +7,  -71,  +60,   +8,  -69,
  +182,   +8,  -67,  +54,   +9,  -64, +188,   +9,  -62,  +74,  +10,  -59,
  +223,  +10,  -56, +123,  +11,  -53,  +32,  +12,  -50, +205,  +12,  -47,
  +131,  +13,  -44,  +66,  +14,  -40,  +10,  +15,  -37, +221,  +15,  -33,
  +185,  +16,  -29, +161,  +17,  -25, +148,  +18,  -21, +146,  +19,  -17,
  +157,  +20,  -13, +181,  +21,   -8, +217,  +22,   -4,  +12,  +24,   +1,
   +77,  +25,   +6, +157,  +26,  +11, +252,  +27,  +16, +107,  +29,  +22,
  +235,  +30,  +28, +124,  +32,  +33,  +31,  +34,  +39, +212,  +35,  +45,
  +156,  +37,  +51, +119,  +39,  +58, +102,  +41,  +64, +103,  +43,  +71,
  +124,  +45,  +78, +163,  +47,  +84, +221,  +49,  +91,  +38,  +52,  +98,
  +124,  +54, +104, +221,  +56, +111,  +67,  +59, +117, +167,  +61, +122,
};

const uint8_t g_vcf_lpf_table_q_1_over_sqrt_2[] = {
   +10,   +0, -124,  +10,   +0, -124,  +11,   +0, -124,  +12,   +0, -124,
   +12,   +0, -123,  +13,   +0, -123,  +14,   +0, -123,  +15,   +0, -123,
   +16,   +0, -123,  +17,   +0, -123,  +18,   +0, -122,  +19,   +0, -122,
   +20,   +0, -122,  +22,   +0, -122,  +23,   +0, -122,  +25,   +0, -121,
   +26,   +0, -121,  +28,   +0, -121,  +30,   +0, -121,  +32,   +0, -120,
   +34,   +0, -120,  +36,   +0, -120,  +38,   +0, -119,  +41,   +0, -119,
   +44,   +0, -119,  +46,   +0, -119,  +49,   +0, -118,  +53,   +0, -118,
   +56,   +0, -117,  +60,   +0, -117,  +63,   +0, -117,  +67,   +0, -116,
   +72,   +0, -116,  +76,   +0, -116,  +81,   +0, -115,  +86,   +0, -115,
   +92,   +0, -114,  +98,   +0, -114, +104,   +0, -113, +111,   +0, -113,
  +118,   +0, -112, +125,   +0, -112, +133,   +0, -111, +141,   +0, -111,
  +150,   +0, -110, +159,   +0, -109, +169,   +0, -109, +180,   +0, -108,
  +191,   +0, -108, +203,   +0, -107, +215,   +0, -106, +229,   +0, -105,
  +243,   +0, -105,   +2,   +1, -104,  +17,   +1, -103,  +34,   +1, -102,
   +52,   +1, -101,  +70,   +1, -101,  +90,   +1, -100, +111,   +1,  -99,
  +133,   +1,  -98, +157,   +1,  -97, +181,   +1,  -96, +207,   +1,  -95,
  +235,   +1,  -94,   +8,   +2,  -92,  +38,   +2,  -91,  +71,   +2,  -90,
  +105,   +2,  -89, +141,   +2,  -88, +179,   +2,  -86, +219,   +2,  -85,
    +5,   +3,  -84,  +49,   +3,  -82,  +96,   +3,  -81, +146,   +3,  -79,
  +197,   +3,  -78, +252,   +3,  -76,  +53,   +4,  -74, +114,   +4,  -73,
  +177,   +4,  -71, +244,   +4,  -69,  +59,   +5,  -67, +132,   +5,  -65,
  +210,   +5,  -64,  +36,   +6,  -62, +121,   +6,  -59, +211,   +6,  -57,
   +50,   +7,  -55, +149,   +7,  -53, +253,   +7,  -51, +106,   +8,  -48,
  +221,   +8,  -46,  +85,   +9,  -43, +212,   +9,  -41,  +89,  +10,  -38,
  +228,  +10,  -35, +118,  +11,  -32,  +16,  +12,  -30, +178,  +12,  -27,
   +91,  +13,  -24,  +14,  +14,  -20, +201,  +14,  -17, +142,  +15,  -14,
   +94,  +16,  -10,  +56,  +17,   -7,  +30,  +18,   -3,  +17,  +19,   +1,
   +17,  +20,   +5,  +32,  +21,   +9,  +62,  +22,  +13, +109,  +23,  +17,
  +175,  +24,  +22,   +4,  +26,  +27, +111,  +27,  +31, +242,  +28,  +36,
  +142,  +30,  +42,  +72,  +32,  +47,  +33,  +34,  +53,  +30,  +36,  +59,
   +66,  +38,  +65, +147,  +40,  +72,  +21,  +43,  +79, +208,  +45,  +86,
  +203,  +48,  +93,  +15,  +52, +101, +166,  +55, +110, +157,  +59, +118,
};

