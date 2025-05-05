%Divisão e Conquista:
v(1).table = readtable('troco_DC40.csv');
v(1).name = "Mét. de Divisão e Conquista";
%Greedy x PD - BR200:
v(2).table = readtable('troco_GR_BR200.csv');
v(2).name = "Mét. Guloso";
v(3).table = readtable('troco_PD_BR200.csv');
v(3).name = "Mét. de Programação Dinâmica";
% Greedy x PD - Greedy perde
v(4).table = readtable('troco_GR_GRLoses.csv');
v(4).name = "Mét. Guloso";
v(5).table = readtable('troco_PD_GRLoses.csv');
v(5).name = "Mét. de Programação Dinâmica";

% Botar nomes de struct, organizando:
for i = 1:length(v)
    v(i).troco = v(i).table{1:end-1 , 1};
    v(i).tempo = v(i).table{1:end-1 , 2};
    v(i).moedas = v(i).table{1:end-1 , 3};
    v(i).calls = v(i).table{1:end-1 , 4};
end

% A - Tempo DC - fig1
figure
y = [v(1)];
plot(v(1).troco, [y.tempo],'LineWidth',2);
hold on;
ylabel('Tempo de execução (ms)')
xlabel('Valor do troco')
legend([y.name])
title('.')
grid on 
hold off

% Chamadas DC - fig2
figure
y = [v(1)];
plot(v(1).troco, [y.calls],'LineWidth',2);
hold on;
ylabel('Quantidade de chamadas recursivas')
xlabel('Valor do troco')
legend([y.name])
title('')
grid on 
hold off

% Moedas DC - fig3
figure
y = [v(1)];
plot(v(1).troco, [y.moedas],'LineWidth',2);
hold on;
ylabel('Número de moedas')
xlabel('Valor do troco')
legend([y.name])
title('.')
grid on 
hold off

%B: Comparação de tempo PD x Greedy - fig4
figure
y = [v(2) v(3)]; % Greedy e PD
plot(v(2).troco, [y.tempo],'LineWidth',2);
hold on;
ylabel('Tempo de execução (ms)')
xlabel('Valor do troco')
legend([y.name])
title('')
grid on 
hold off

%B Comparação de moedas PD x Greedy fig5
figure
y = [v(2) v(3)];
plot(v(2).troco, [v(2).moedas],'LineWidth',2,'LineStyle','-');
hold on;
plot(v(2).troco, [v(3).moedas],'LineWidth',2,'LineStyle','--');
hold on;
ylabel('Número de moedas')
xlabel('Valor do troco')
legend([y.name])
title('')
grid on 
hold off

%C: Comparação de tempo PD x Greedy - Greedy perde fig6
figure
y = [v(4) v(5)]; % Greedy Loses e PD Loses
plot(v(4).troco, [y.tempo],'LineWidth',2);
hold on;
ylabel('Tempo de execução (ms)')
xlabel('Valor do troco')
legend([y.name])
title('')
grid on 
hold off

%C Comparação de moedas PD x Greedy - Greedy perde fig7
figure
y = [v(4) v(5)];
plot(v(4).troco, [v(4).moedas],'LineWidth',2,'LineStyle','-');
hold on;
plot(v(4).troco, [v(5).moedas],'LineWidth',2,'LineStyle','--');
hold on;
ylabel('Número de moedas')
xlabel('Valor do troco')
legend([y.name])
title('')
grid on 
hold off