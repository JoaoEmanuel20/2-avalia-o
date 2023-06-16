ALUNO: JOAO EMANUEL 01349009

TURMA: CIÊNCIA DA COMPUTAÇÃO  (7P)



1 - - def eliminate_left_recursion(grammar):
    non_terminals = list(grammar.keys())
    for i in range(len(non_terminals)):
        A = non_terminals[i]
        productions_A = grammar[A]
        new_productions_A = []
        new_non_terminal = A + "_new"
        direct_recursion = []
        indirect_recursion = []
        for production in productions_A:
            if production[0] == A:
                direct_recursion.append(production[1:] + new_non_terminal)
            else:
                indirect_recursion.append(production + new_non_terminal)
        if direct_recursion:
            new_productions_A.extend(indirect_recursion + [new_non_terminal + ' -> ' + production for production in direct_recursion] + ['?'])
        else:
            new_productions_A.extend(indirect_recursion)
        grammar[A] = new_productions_A
 
def convert_to_greibach_form(grammar):
    eliminate_left_recursion(grammar)
    return grammar
 
# Gramática original
original_grammar = {
    'S1': ['aS2d', 'ad', 'ac', 'cc', 'aB3c', 'cB3c'],
    'S2': ['ac', 'cc', 'aB3c', 'cB3c'],
    'S3': ['a', 'c', 'aB3', 'cB3'],
    'B3': ['cc', 'ccB3']
}
 
# Converter para FNG
greibach_form = convert_to_greibach_form(original_grammar)
 
# Imprimir a gramática em FNG
for non_terminal, productions in greibach_form.items():
    for production in productions:
        print(non_terminal + ' -> ' + production)
