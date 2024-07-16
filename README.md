## Projekat: Simulator mreže gradskog prevoza

### Funkcionalna specifikacija

**Opis projekta:**
Na programskom jeziku C++ implementirati simulator mreže gradskog prevoza. Potrebno je napisati skup klasa sa odgovarajućim metodama, konstruktorima, operatorima i destruktorima za realizaciju sistema.

### Učitavanje podataka o mreži gradskog prevoza

1. **Podaci o stajalištima:**
   - Učitati podatke iz tekstualnog fajla koji sadrži informacije o stajalištima.
   - Format fajla: `šifra_stajališta naziv_stajališta [!]`, gde `[!]` označava važna stajališta.
   - Primer: `585 Tehnički fakulteti [!]`

2. **Podaci o linijama:**
   - Učitati podatke iz tekstualnog fajla koji sadrži informacije o linijama.
   - Format fajla: `oznaka_linije stajališta`, gde su stajališta šifre stajališta kroz koja linija prolazi.
   - Primer: `EKO1 654 585 583 190`

### Prikaz informacija o mreži gradskog prevoza

1. **Informacije o stajalištu:**
   - Na osnovu zadate šifre stajališta prikazati informacije o tom stajalištu.
   - Informacije uključuju: šifru stajališta, naziv stajališta, oznake svih linija koje prolaze kroz dato stajalište i šifre važnih stajališta direktno povezanih sa datim stajalištem.
   - Primer formata: `585 Tehnički fakulteti [26 27 74 EKO1] {! 551 556 583 654 !}`
   - Rezultate zapisati u tekstualni fajl `stajaliste_sifra_stajalista.txt`.

2. **Informacije o liniji:**
   - Na osnovu zadate oznake linije prikazati informacije o toj liniji.
   - Informacije uključuju: oznaku linije, početno i krajnje stajalište, šifre i nazive svih stajališta kroz koja linija prolazi.
   - Primer formata: `EKO1 Vukov spomenik->Naselje Belville`
   - Rezultate zapisati u tekstualni fajl `linija_oznaka_linije.txt`.

### Simulacija kretanja kroz mrežu gradskog prevoza

1. **Generisanje putanje:**
   - Na osnovu odabranog početnog i krajnjeg stajališta generisati putanju između njih.
   - Rezultat simulacije zapisati u tekstualni fajl `putanja_pocetak_kraj.txt`.
   - Format fajla: Linija na koju se preseda i niz šifara stajališta kroz koja se prolazi.
   - Primer formata: 
     ```
     16
     363 298 360
     16->EKO1
     360 703 534 582 584
     ```
   
2. **Strategije pronalaženja putanje:**
   - Prva strategija: pronalazi bilo koju putanju između početnog i krajnjeg stajališta.
   - Druga strategija: pronalazi putanju sa najmanjim brojem presedanja.
   - Treća strategija: pronalazi putanju koja obilazi sva važna stajališta.

### Interakcija sa korisnikom

1. **Interaktivni sistem:**
   - Korisnik interaguje sa sistemom odabirom opcija koje sistem nudi.
   - Mogućnosti uključuju učitavanje podataka, prikaz informacija o stajalištu ili liniji, pronalazak putanje.
   - Primer interakcije:
     ```
     Dobrodošli u simulator mreže gradskog prevoza. Molimo Vas, odaberite opciju:
     1. Učitavanje podataka o mreži gradskog prevoza
     0. Kraj rada
     1
     Molimo Vas, unesite putanju do fajla sa stajalištima ili kliknite ENTER za učitavanje podrazumevanog fajla (ulazi/stajalista.txt):
     ...
     ```

2. **Detaljne poruke o greškama:**
   - Program treba da generiše detaljne poruke o greškama kako bi korisnik mogao lakše da ih otkloni.




**ENGLISH**

## Project: Public Transport Network Simulator

### Functional Specification

**Project Description:**
Implement a simulator for a public transport network using C++. The project involves creating a set of classes with appropriate methods, constructors, operators, and destructors to realize the system.

### Loading Public Transport Network Data

1. **Stop Data:**
   - Load data from a text file containing information about stops.
   - File format: `stop_code stop_name [!]`, where `[!]` indicates important stops.
   - Example: `585 Technical Faculties [!]`

2. **Line Data:**
   - Load data from a text file containing information about lines.
   - File format: `line_code stops`, where stops are the codes of stops that the line passes through in both directions.
   - Example: `EKO1 654 585 583 190`

### Displaying Public Transport Network Information

1. **Stop Information:**
   - Display information about a stop based on a given stop code.
   - Information includes: stop code, stop name, codes of all lines passing through the stop, and codes of all important stops directly connected to the given stop.
   - Example format: `585 Technical Faculties [26 27 74 EKO1] {! 551 556 583 654 !}`
   - Write the result to a text file named `stop_stop_code.txt`.

2. **Line Information:**
   - Display information about a line based on a given line code.
   - Information includes: line code, start and end stops, and codes and names of all stops that the line passes through.
   - Example format: `EKO1 Vukov spomenik->Naselje Belville`
   - Write the result to a text file named `line_line_code.txt`.

### Simulating Movement Through the Public Transport Network

1. **Generating a Route:**
   - Generate a route between the selected start and end stops.
   - Write the simulation result to a text file named `route_start_end.txt`.
   - File format: Line to transfer to and a series of stop codes through which the line passes.
   - Example format:
     ```
     16
     363 298 360
     16->EKO1
     360 703 534 582 584
     ```

2. **Pathfinding Strategies:**
   - First strategy: find any path between the start and end stops.
   - Second strategy: find the path with the fewest transfers.
   - Third strategy: find the path that visits all important stops.

### User Interaction

1. **Interactive System:**
   - The user interacts with the system by selecting options provided by the system.
   - Options include loading data, displaying stop or line information, finding a route.
   - Example interaction:
     ```
     Welcome to the public transport network simulator. Please select an option:
     1. Load public transport network data
     0. Exit
     1
     Please enter the path to the file with stops or press ENTER to load the default file (inputs/stops.txt):
     ...
     ```

2. **Detailed Error Messages:**
   - The program should generate detailed error messages to help the user troubleshoot issues.

### Notes

- The system should be well-commented, modular, and easily extendable.
- In cases of unclear requirements, make reasonable assumptions and build the solution based on those assumptions.
