from pyvis.network import Network

net = Network()

net.add_nodes(
    [1, 2, 3, 4, 5, 6],
    label=['Студент Маша 1', 'Студент Саша 2', 'Студент Петя 3', 'Студент Даша 4', 'Студент Игорь 5', 'Студент Петр 6'],
    title=['Main node', 'Just node', 'Just node', 'Just node', 'Just node', 'Node with self-loop'],
    color=['#d47415', '#22b512', '#42adf5', '#4a21b0', '#e627a3', '#e627a3']
)

net.add_edges([(1, 2), (1, 3), (2, 3), (2, 4), (3, 5), (4, 6)])

net.show('graph.html')