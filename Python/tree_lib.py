class Queue:
	def __init__(self):
		self._data = []

	def push(self, x):
		self._data.append(x)

	def pop():
		return self._data.pop(0)

	def empty():
		return len(self._data) == 0

def height(tree):
	if not tree:
		return 0
	return 1 + max(height(tree.left), height(tree.right))

def dfs_nodes(tree):
	if tree:
		yield tree
		yield from dfs_nodes(tree.left)
		yield from dfs_nodes(tree.right)

def bfs_nodes(tree):
	queue = []
	queue.append(tree)

	while queue:
		node = queue.pop(0)
		if node:
			yield node
			yield from bfs_nodes(node.left)
			yield from bfs_nodes(node.right)

def dfs_pre_order(tree):
	if tree:
		yield tree
		yield from dfs_pre_order(tree.left)
		yield from dfs_pre_order(tree.right)

def dfs_in_order(tree):
	if tree:
		yield from dfs_in_order(tree.left)
		yield tree
		yield from dfs_in_order(tree.right)

def dfs_post_order(tree):
	if tree:
		yield from dfs_post_order(tree.left)
		yield from dfs_post_order(tree.right)
		yield tree

def traverse_pre_order(tree, visitor=print):
	if tree:
		visitor(tree)
		traverse_pre_order(tree.left, visitor)
		traverse_pre_order(tree.right, visitor)

def traverse_in_order(tree, visitor=print):
	if tree:
		traverse_in_order(tree.left, visitor)
		visitor(tree)
		traverse_in_order(tree.right, visitor)

def traverse_post_order(tree, visitor=print):
	if tree:
		traverse_post_order(tree.left, visitor)
		traverse_post_order(tree.right, visitor)
		visitor(tree)

