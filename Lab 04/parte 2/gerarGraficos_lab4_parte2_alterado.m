str_ini = "SSP_Tests_";
str_meio = "Timed_"; % "Timed_"; (Alterar dependendo de qual gerador)
algs = ["DD","A2","PD"]; % Coloque os algoritmos que vc botou no Tests_Aluno
gers = ["P3", "P4", "P5","RAND", "EVOD","AVIS"]; % Coloque os geradores de instancia
str_fim = ".dat";

for i = 1:size(algs,2)
    for j = 1:size(gers,2)
        path = str_ini + str_meio + algs(i) + "_" + algs(i) + "_" + gers(j) + str_fim;
        v(i,j).table = readtable(path);
        v(i,j).name = algs(i);
        v(i,j).size = v(i,j).table{:,1};
        v(i,j).time = v(i,j).table{:,2};
    end
end

for j = 1:size(gers,2)
    figure;
    y = v(:,j)';
    plot(v(1).size, [y.time], 'LineWidth', 2);
    hold on;
    ylabel('Tempo médio de execução (ms)');
    xlabel('Tamanho do input (quantidade de itens)');
    legend([y.name]);
    title('Comparação de tempo para o gerador de instâncias ' + gers(j));
    grid on;
    hold off;
    
    % Save the figure as PNG
    saveas(gcf, gers(j) + ".png");
end
