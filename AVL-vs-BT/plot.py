import matplotlib.pyplot as mtplt

number_sort = []
lst = []
bst = []

dataset = open('out.txt', 'r')

for line in dataset:
    line = line.strip()
    NS, AVL, BST = line.split(' ')
    number_sort.append(int(NS))
    lst.append(int(AVL))
    bst.append(int(BST))


fig, ax = mtplt.subplots()

ax.set_title('AVL x BST')
ax.set_xlabel('Número Gerado')
ax.set_ylabel('Número de Comparações')

color = 'tab:blue'
ax.scatter(number_sort, lst, color = color, label = "AVL")

color = 'tab:red'
ax.scatter(number_sort, bst, color = color, label = "BST")

ax.legend()

mtplt.show()