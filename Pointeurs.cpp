/*Salut, ça c'est un fichier pour se rappeller / apprendre comment ça marche les pointeurs en C++
Il est compilable et exécutable, mais ce qui compte, c'est évidemment les sources*/

#include <cstdlib> //Pour le "system("pause");"
#include <iostream>

int multiply(int, int);
void pointerMultiply(int*, int);

int main()
{
	//On déclare une variable a
	int a = 1337;
	//Ma foi tout ce quil y a de plus classique, on peut vérifier ça facilement
	std::cout << "La variable 'a' vaut " << a << "." << std::endl;

	/*Maintenant, on va commencer à parler de pointeurs
	Il y a deux types de pointeurs
	On va commencer avec les pointeurs sur varaibles (d'où la variable 'a", pas bête hein ?)*/
	int* pointer_on_a = &a;
	/*Voilà, rien de plus simple
	On va expliquer ce qui se passe, évidemment
	'pointer_on_a' contient l'adresse de la case en mémoire où est stockée 'a', un grand nombre chelou qu'on osef total
	On peut encore une fois vérifier ça*/
	std::cout << "La case en memoire où est stockee 'a' est " << pointer_on_a << "." << std::endl;
	//On peut aussi accéder à l'adresse comme ça par le chemin
	std::cout << "La case en memoire où est stockee 'a' est toujours " << &a << "." << std::endl;
	//Si on veut accéder à la valeur de 'a' par le pointeur, on fait comme ça
	std::cout << "La variable 'a' stockee en case " << pointer_on_a << " vaut " << *pointer_on_a << "." << std::endl;

	/*====================*/

	/*Ça c'est les pointeurs faciles, y a pas d'histoire de delete ou quoi
	Maintenant, on va voir les pointeurs avec allocation dynamique (Brrr ça fait peur)
	Ce coup-là, pas de variable, direct un pointeur*/
	int* dynamic_pointer = new int;
	/*Ah, le fameux new ! Eh oui, le cauchemar commence !
	Bon c'est bien sympa, mais comment je m'en sers moi de ce pointeur ?
	Eh bien exactement comme l'autre*/
	*dynamic_pointer = 42;
	std::cout << "Le pointer 'dynamic_pointer' pointe sur la case " << dynamic_pointer << " qui contient la valeur " << *dynamic_pointer << "." << std::endl;
	/*Eh voilà, c'est pas si dur !
	Maintenant on va un peu parler des fonctions
	Plus haut, j'ai déclarer deux fonctions, une qui renvoie un 'int' et une qui renvoie rien
	Celle qui renvoie quelque chose attend un 'int' classico*/
	int b = 5;
	std::cout << "'b' vaut " << b << std::endl;

	b = multiply(b, 10);
	std::cout << "Apres multiplication, b vaut " << b << "." << std::endl;

	/*Maintenant on va parler de la deuxième fonction
	Elle attend un pointeur et renvoi rien
	C'est normal, parce qu'elle va directement aller modifier la valeur contenue dans la case pointée, pas besoin de retourner quoi que ce soit !
	On va reprendre notre pointeur dynamique*/
	pointerMultiply(dynamic_pointer, 5);
	std::cout << "Apres multiplication, la valeur stockee en case pointee par 'dynamic_pointer' vaut " << *dynamic_pointer << "." << std::endl;
	/*Et voilà, le tour est joué !
	Maintenant, l'étape LA PLUS IMPORTANTE !*/
	delete dynamic_pointer;
	//À ne jamais oublier ! Sans ça, la valeur va rester en mémoire, et ça va provoquer les fameuses "fuites de mémoire" !

	/*====================*/

	/*Voilà, c'est fini !
	Comme quoi, les pointeurs, c'est pas compliqué !*/

	system("pause"); //Ça c'est parce que je compile avec GCC, inutile sous la plupart des IDE

	return 0;
}

int multiply(int _number_to_multiply, int _multiplying_factor)
{
	return _number_to_multiply * _multiplying_factor;
}

void pointerMultiply(int* _number_to_multiply, int _multiplying_factor)
{
	*_number_to_multiply *= _multiplying_factor;

	return; //Optionnel
}
