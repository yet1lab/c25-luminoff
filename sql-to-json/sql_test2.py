import sqlite3
import pandas as pd #

conn = sqlite3.connect("db copy.sqlite3")

lista_de_horarios_fim = ['18:30:00', '20:10:00']  # Exemplo de lista de horários de fim

z = "20:10:00"  # Exemplo de horário específico

sql = F"""
SELECT 
    count(*)
FROM core_horarioturma LEFT JOIN core_sala ON core_horarioturma.sala_id = core_sala.id
WHERE core_horarioturma.hora_fim IN ('{z}');
"""

df = pd.read_sql_query(sql, conn) 

print(df)

conn.close()