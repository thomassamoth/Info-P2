// Fonction permettant de coder un caract�re
// selon la m�thode indiqu�e dans l'�nonc�:
char code_lettre(char lettre)
{
    // Lettres A � V :
    if(lettre >= 'A' && lettre <= 'V')
        return lettre + 36;
    // Lettres W � Z :
    if(lettre >= 'W' && lettre <= 'Z')
        return lettre + 10;
    // Lettre a � v :
    if(lettre >= 'a' && lettre <= 'v')
        return lettre - 28;
    // Lettre w � z :
    if(lettre >= 'w' && lettre <= 'z')
        return lettre - 54;
    // Autres caract�res :
    return lettre;
}

main()
{
    char texte[50];
    int i = 0;

    printf("Entrez une chaine de caracteres : ");
    fgets(texte, 50, stdin);

    while(texte[i] != '\0')
    {
        texte[i] = code_lettre(texte[i]); // Appel de la fonction
        i++;
    }
    printf("Message code : %s\n",texte);
}