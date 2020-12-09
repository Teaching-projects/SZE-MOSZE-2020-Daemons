# Tagok

| Név | Github azonosito  | Javasolt relatív érdemjegy | Becsült óra | Indoklás  |
| --- | ---- | --- | ------------------ | --------- |
| Kulcsár Bence | @kulcsarbence | 0 | 30-40 |  |
| Mesics Mátyás | @mesmatyi | 0 | 30-40 |  |
| Lázár Tamás | @Lazar-source | 0 | 30-40 |  |


# Videók

 - [Gameplay](/videos/gameplay.mp4)
 - [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat | Merge ideje a határidóhöz (nap) | Change request körök | Reviewer |
| ------- | ------------------------------- | -------------------- | -------- |
| Feladat 1 | +2 | 3 | @hegyhati |
| Feladat 2 | 0 | 1 | @hegyhati |
| jsonparser | +2 | 1 | @wajzy |
| levelup | -2 | 1 | @oliverosz |
| attackspeed | 0 | 1 | @vizvezetek |
| documentation | -8 | 1 | @Vodor / @petinexus, @rolandborbely |
| unittests | -8 | 1 | @Vodor / @petinexus, @rolandborbely  |
| makefile | -6 | 2 | @hegyhati |
| refactor | +2 | 1 | @hegyhati |
| docker | -4 | 1 | @hegyhati |
| jsonpimp | Merge: 11.15 | 0 | @Lazar-source |
| map | Merge: 11.19 | 0 | @Vodor /  @rolandborbely |
| game | Merge: 11.26 | 1 | @Vodor / @rolandborbely |
| defense | Merge: 11.24 | 1 | @Vodor / @rolandborbely |
| damage | Merge: 11.24 | 1 | @Vodor / @rolandborbely  |
| markedmap | Merge: 12.01 | 1 | @Vodor / @petinexus |
| preparedgame | Merge: 12.03| 1 | @Vodor/@rolandborbely
| light radius | Merge: 12.02 | 1 | @Vodor / @rolandborbely |
| rendering | Merge: 12.06 | 2 | @Vodor / @petinexus, @rolandborbely |

# Unit tesztek

| Osztály | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| --- | --- | --- | --- |
| `Hero` | 18 | 12 | 19 |
| `Monster` | 10 | 7 | 9 |
| `Map` | 3 | 2 | 8 |
| `Markedmap` | 2 | 0 | 1|
| `Game` | 11 | 2 | 2 |
| `PreparedGame` | 1 | 0 | 0 |
| `JSON` | 6| 1 | 4 |
| `HeroTextRenderer` | 1 | 0 | 0 |
| `ObserverSVGRenderer` | 1 | 0 | 0 |
| `ObserverTextRenderer` | 1 | 0 | 0 |
| `Renderer` | 1 | 0 | 0 |
| `SVGRenderer` | 1 | 0 | 0 |
| `TextRenderer` | 2 | 0 | 0 |
| - |

# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| --- | --- | --- |  
| `Hero` |  -|  -  |  
| `Monster` | - | - |  
| `Game` | - | - |
| `JSON` | - | - |
| `Map` | - |- |
| `MarkedMap` | - | - |
| `HeroTextRenderer`| - | - |
| `ObserverSVGRenderer`| - |  - |
| `ObserverTextRenderer`| - | - |
| `Renderer`| - | - |
| `SVGRenderer`| - | - |
| `TextRenderer`| - | - |
| ... |


# Mindenféle számok

 - Összes cpp kódsor  : 793
 - Egyéb kódsor (make,doxyfile,shellscript, -) : 50(.yml), 10(.sh) 66(Makefile)
 - cppcheck
   - warning : 0
   - style : 15
   - performance : 4
   - unusedFunction : 0
   - missingInclude : 0

# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - alapvető shell/python scripting
 - `std::variant`
 - SVG
 - GHA elsajátítása

# Feedback (optional)

@kulcsarbence Nagyon hasznosnak találtam, főleg a dockeres és a unit tesztelős részt, ugyanis ezeket a dolgokat mostanában kezdtem el használni is a munkámban,:
fontos technológiáknak tartom őket.

# Üzenet a jövőbe (optional)

Így, hogy túlvagytok rajta, mi az, aminek örültetek volna, ha első héten elmondom, avagy: jövőre mit lenne jó, ha elmondanék majd?:
@Lazar-source Nekem személyesen egy összkép hiányzott arról hogy pontosan mikkel is fogunk majd dolgozni a tárgy során. Akár csak felsorolás szerűen: makefile,docker,doxconf,unittest jó lett volna egybe látni már a legelején.
@kulcsarbence Szerintem mindent kimerítő volt a tárgy, de amit @Lazar-source írt, azzal egyetértek.\
@mesmatyas Szerintem is jó és hasznos volt, személy szerint még örültem volna ha van még egy-kettő CI/CD-hoz kapcsolodó feladat.
