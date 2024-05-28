Aplicatia este alcatuita din 8 fisiere si este folosita pentru a simula un turneu.

Fisierul header struct.h in care am definit toate structurile si toate prototipurile functiilor pe care le-am folosit.

Fisierul main.c care este partea principala a aplicatiei unde se deschid fisierele necesare si se apeleaza functiile care rezolva cerintele.

Fisierul tasks.c este folosit pentru a rezolva toate cele 5 cerinte. In acest fisier gasim toate functiile care rezolva problema. 
- Functia task1 este folosita pentru a crea lista cu echipele din fisier si pentru a scrie in fisierul de output numele echipelor.
- Functia task2 este folosita pentru a crea lista cu echipe si pentru a sterge echipele cu cel mai mic punctaj astfel incat sa ramana un numar de echipe care sa fie maxim si sa fie o putere a lui 2, iar dupa ce am sters echipele scriem in fisierul de output echipele ramase.
- Functia task3 este folosita pentru a simula meciurile dintre echipele ramase de la cerinta anterioara. Pentru a simula aceste meciuri am folosit o coada in care am pus toate echipele si doua stive, una pentru castigatori, iar cealalta pentru pierzatori. Cu ajutorul functiei playMatches, in fisier se vor scrie echipele care joaca meciurile din runda respectiva, iar la finalul rundei se vor scrie castigatorii. Functia urmeaza urmatorii pasi: din coada am luat cate 2 echipe si le-am comparat punctele, iar echipa cu punctajul mai mare castiga, primeste un punct si este pusa in stiva castigatorilor, iar echipa care pierde este pusa in stiva pierzatorilor. In cazul in care cele 2 echipe au acelasi punctaj, echipele se vor compara dupa nume in ordine alfabetica descrescatoare. Dupa am scris in fisierul de output castigatorii rundei respective din stiva castigatorilor. Dupa ce am simulat meciurile din runda respectiva, am eliminat echipele din stiva invinsilor si am pus inapoi in coada echipele din stiva castigatorilor pentru a simula urmatoarea runda pana cand se ajunge la ultima runda.
- Functia task4 este folosita pentru a introduce cele mai bune 8 echipe din turneu intr-un arbore binar de cautare si de a le scrie la finalul fisierului de output in inordine. Parcurgem arborele in inordine, deoarece este BST, iar aceasta parcurgere afiseaza echipele in ordine descrescatoare.
- Functia task5 este folosita pentru a converti arborele BST de la cerinta 4 intr-un arbore AVL echilibrat si pentru a scrie la finalul fisierului de output echipele de pe nivelul 2 al arborelui AVL. Pentru a converti arborele BST in AVL am parcurs in inordine arborele BST si am pus toate echipele intr-un vector de echipe, pastrand la fiecare iteratie cu ajutorul unui pointer indexul echipei curente pentru a avea indexul ultimului element din vector. Apoi am creat arborele AVL cu ajutorul vectorului creat anterior punand de fiecare data in subarborele stang doar jumatatea din partea stanga a vectorului pana cand se ajunge la primul element, iar in subarborele drept jumatatea din partea dreapta a vectorului pana se ajunge la ultimul element, radacina fiind mijlocul vectorului. Dupa ce am convertit arborele, am printat echipele de pe nivelul 2.

Fisierul liste.c contine toate functiile pe care le-am folosit pentru a lucra cu liste, cum ar fi: createTeamList, addTeamAtBeggining, tPoints care calculeaza punctajul echipei.

Fisierul cozi.c contine toate functiile pe care le-am folosit pentru a lucra cu cozi, cum ar fi: enQueue, deQueue, isQueueEmpty etc.

Fisierul stive.c contine toate functiile pe care le-am folosit pentru a lucra cu stive, cum ar fi: push, pop, isStackEmpty etc.

Fisierul arbori.c contine toate functiile pe care le-am folosit pentru a lucra cu arbori, cum ar fi: newNodeBST, newNodeAVL, rightRotate, leftRotate insertBST, insertAVL etc.

Fisierul Makefile in care sunt comenzile din Linux care compileaza toate aceste fisiere si creeaza fisierul obiect care poate fi executat si care sterge fisierul obiect dupa ce acesta isi termina executia.
