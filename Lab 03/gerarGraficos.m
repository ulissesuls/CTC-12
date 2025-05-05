%Mergesort:
v(1).table = readtable('MRG_I_MS_RAND_200_20000.csv');
v(1).name = "";
v(2).table = readtable('MRG_R_MS_RAND_200_20000.csv');
v(2).name = "";
%Quicksort:
v(3).table = readtable('QS_1R_MS_AO_200_20000.csv');
v(3).name = "";
v(4).table = readtable('QS_1R_MS_RAND_200_20000.csv');
v(4).name = "";
v(5).table = readtable('QS_2R_MS_AO_200_20000.csv');
v(5).name = "";
v(6).table = readtable('QS_2R_MS_RAND_200_20000.csv');
v(6).name = "";
v(7).table = readtable('QS_FP_MS_AO_200_20000.csv');
v(7).name = "";
v(8).table = readtable('QS_FP_MS_RAND_200_20000.csv');
v(8).name = "";
%Radix Sort:
v(9).table = readtable('RADIX_MS_RAND_200_20000.csv');
v(9).name = "";
%STL Sort:
v(10).table = readtable('STL_SORT_MS_AO_200_20000.csv');
v(10).name = "";
v(11).table = readtable('STL_SORT_MS_RAND_200_20000.csv'); 
v(11).name = "";

% Botar nomes de struct:
for i = 1:length(v)
    v(i).time = v(i).table{:,1};
    v(i).size = v(i).table{:,3};
    v(i).calls = v(i).table{:,4};
    v(i).depth = v(i).table{:,5};
end

% A - Comparação de Tempo QuickSort X MergeSort-Iterativo X RadixSort x std::sort
%Considerando QS mais rapido como de 1 recursao aleatorio (4)
figure
y = [v(4) v(1) v(9) v(11)];
plot(v(1).size, [y.time],'LineWidth',2);
hold on;
ylabel('Tempo de ordenação (ms)')
xlabel('Tamanho do vetor')
legend([y.name])
title('')
grid on 
print -dpng -r400 grafico400.png
hold off


%Chamadas Recursivas: QuickSort X MergeSort-Iterativo X RadixSort 
figure
y = [v(4) v(1) v(9) ];
plot(v(1).size, [y.calls],'LineWidth',2);
hold on;
ylabel('Número de chamadas recursivas')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

%Profundidade Recursiva: QuickSort X MergeSort-Iterativo X RadixSort
figure
y = [v(4) v(1) v(9) ];
plot(v(1).size, [y.depth],'LineWidth',2);
hold on;
ylabel('Profundidade das recursões')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

% B- MergeSort Recursivo x Iterativo
%Comparação de Tempo do Mergesort
figure
y = v(1:2);
plot(v(1).size, [y.time],'LineWidth',2);
hold on;
ylabel('Tempo de ordenação (ms)')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

%Comparação de números de chamadas recursivas do Quicksort:
figure
y = v(1:2);
plot(v(1).size, [y.calls],'LineWidth',2);
hold on;
ylabel('Número de chamadas recursivas')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

%Comparação de números de profundidade recursivas do Quicksort:
figure
y = v(1:2);
plot(v(1).size, [y.depth],'LineWidth',2);
hold on;
ylabel('Profundidade das recursões')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off


% C -  QuickSort com 1 recursão  x QuickSort com 2 recursões 
%Comparação de Tempo do Quicksort
figure
y = v(3:6);
plot(v(1).size, [y.time],'LineWidth',2);
hold on;
ylabel('Tempo de ordenação (ms)')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

%Comparação de números de chamadas recursivas do Quicksort:
figure
y = v(3:6);
plot(v(1).size, [y.calls],'LineWidth',2);
hold on;
ylabel('Número de chamadas recursivas')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

%Comparação de números de profundidade recursivas do Quicksort:
figure
y = v(3:6);
plot(v(1).size, [y.depth],'LineWidth',2);
hold on;
ylabel('Profundidade das recursões ')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off


% D - QuickSort com mediana de 3 x Quicksort com pivô fixo para vetores quase ordenados
%Comparação de Tempo do Quicksort
figure
y = v(3:8);
plot(v(1).size, [y.time],'LineWidth',2);
hold on;
ylabel('Tempo de ordenação (ms)')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

%Comparação de números de chamadas recursivas do Quicksort:
figure
y = v(3:8);
plot(v(1).size, [y.calls],'LineWidth',2);
hold on;
ylabel('Número de chamadas recursivas')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off

%Comparação de números de profundidade recursivas do Quicksort:
figure
y = v(3:8);
plot(v(1).size, [y.depth],'LineWidth',2);
hold on;
ylabel('Profundidade das recursões')
xlabel('Tamanho do vetor')
legend([y.name])
title('.')
grid on 
print -dpng -r400 grafico400.png
hold off
