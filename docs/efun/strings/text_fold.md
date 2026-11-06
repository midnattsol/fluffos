---
title: strings / text_fold
---
# text_fold

### NAME

    text_fold() - the form two texts are compared in, without case or accents

### SYNOPSIS

    string text_fold( string str );

### DESCRIPTION

    Return str with its combining marks removed and its case folded, by Unicode
    rules: "LEÑA", "leña" and "lena" all give "lena", "ÞÓR" gives "þor", and
    "Straße" gives "strasse". The original string remains unchanged.

    Use it to compare what a person typed with a name. It is not for display.

    Letters of their own, such as æ, ø, ð and þ, are not accented forms of
    another letter and stay as they are; what they spell in ASCII is for the
    mudlib to decide.

### SEE ALSO

    lower_case(3)
