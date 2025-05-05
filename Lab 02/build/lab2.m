%recolhendo os dados
data = readtable('oak_search.csv');
matriz=data{:,:};
elementos=matriz(:,2);
Lelementos=log(matriz(:,2));
buscaSTL=matriz(:,3);
LbuscaSTL=log(matriz(:,3));
buscaAluno=matriz(:,4);
LbuscaAluno=log(matriz(:,4));
inserirSTL=matriz(:,5);
LinserirSTL=log(matriz(:,5));
inserirAluno=matriz(:,6);
LinserirAluno=log(matriz(:,6));

%ajustando o modelo
coeficientesbuscaAl = polyfit(Lelementos,buscaAluno , 1);
coeficientesbuscaSTL = polyfit(Lelementos,buscaSTL , 1);
coeficientesinserirAl = polyfit(Lelementos,inserirAluno , 1);
coeficientesinserirSTL = polyfit(Lelementos,inserirSTL , 1);

% Usando os coeficientes para criar um modelo logarítmico
a1 = coeficientesbuscaAl(1)
b1 = coeficientesbuscaAl(2)

a2 = coeficientesbuscaSTL(1);
b2 = coeficientesbuscaSTL(2);

a3 = coeficientesinserirAl(1);
b3 = coeficientesinserirAl(2);

a4 = coeficientesinserirSTL(1);
b4 = coeficientesinserirSTL(2);

modeloLogbuscAl = @(x)(a1*log(x) + b1);
modeloLogbuscSTL = @(x) a2*log(x) + b2;
modeloLoginsAl = @(x) a3*log(x) + b3;
modeloLoginsSTL = @(x) a4*log(x) + b4;

%Plotar os graficos
figure;
plot(elementos, buscaAluno, 'r-');
hold on;
plot(elementos, buscaSTL, 'b-');
hold on;
fplot(modeloLogbuscAl, [min(elementos), max(elementos)], 'r--');
hold on;
fplot(modeloLogbuscSTL, [min(elementos), max(elementos)],'b--');
grid on;
xlabel('Quantidade de elementos');
ylabel('tempo (µs)');
legend('Aluno', 'STL', 'Modelo Log Aluno', 'Modelo Log STL');
title('Gráfico do tempo de busca')
% Finaliza a adição de gráficos
hold off;


figure;
plot(elementos, inserirAluno,'r-');
hold on;
plot(elementos, inserirSTL,'b-');
hold on;
fplot(modeloLoginsAl, [min(elementos), max(elementos)], 'r--');
hold on;
fplot(modeloLoginsSTL, [min(elementos), max(elementos)], 'b--');
grid on;
grid on;
xlabel('Quantidade de elementos');
ylabel('tempo (µs)');
legend('Aluno', 'STL', 'Modelo Log Aluno', 'Modelo Log STL');
title('Gráfico do tempo de inserção')
% Finaliza a adição de gráficos
hold off;