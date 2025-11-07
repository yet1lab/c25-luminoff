import sqlite3
import pandas as pd #

conn = sqlite3.connect("db.sqlite3")


sql = "SELECT core_horarioturma.id, core_horarioturma.dia_semana, core_horarioturma.hora_inicio, core_horarioturma.hora_fim, core_sala.nome as id_da_sala, core_horarioturma.turma_id FROM core_horarioturma left join core_sala on core_horarioturma.sala_id = core_sala.id;"

df = pd.read_sql_query(sql, conn) 

print(df)

conn.close()