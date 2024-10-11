# Morse Code LED Converter
Popis

Tento projekt převádí zadaný text na Morseovu abecedu pomocí LED diody. LED bliká v odpovídajících vzorcích pro tečky a čárky, což umožňuje vizuální reprezentaci Morseova kódu.
Jak to fungujes

    Připojení: LED je připojena k pinu 2 na Arduino desce.
    Vstup: Po spuštění programu můžete zadat zprávu přes sériový monitor.
    Převod: Každé písmeno a číslo v textu se převádí na Morseovu abecedu:
        Tečka (.) odpovídá krátkému záblesku LED.
        Čárka (-) odpovídá delšímu záblesku LED.
    Pauzy: Mezi tečkami a čárkami je malá mezera, mezi písmeny je větší mezera a mezi slovy největší.

Použití

    Otevřete sériový monitor a zadejte text, který chcete převést.
    LED dioda začne blikat podle Morseovy abecedy.
    Po dokončení můžete zadat další zprávu.

Konfigurace

    Délka tečky: dotDuration (ms)
    Délka čárky: dashDuration (ms)

Závislosti

    Arduino IDE

Licenční informace

Tento projekt je open-source a může být použit a upraven podle potřeby.
