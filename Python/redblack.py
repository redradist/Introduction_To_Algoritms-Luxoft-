import networkx as nx
import math
from random import shuffle
import matplotlib.pyplot as plt
import tree_lib

class RedBlackTree:
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right
		self.parent = None
		self.is_black = True

		if self.left:
			self.left.parent = self
		if self.right:
			self.right.parent = self

	def height(self):
		size = 1
		hl = 0; hr = 0
		if self.left != None:
			hl = self.left.height()
		if self.right != None:
			hr = self.right.height()
		if hl > hr:
			size += hl
		elif hl < hr:
			size += hr
		else:
			size += hl
		return size

	def is_balanced(sleft):
		"""
		
		"""
		pass

	def __lt__(self, other):
		return self.data < other.data

	def __le__(self, other):
		return self.data <= other.data

	def __str__(self):
		return str(self.data)

	def nodes(self):
		yield from dfs_pre_order(self)

	def to_graph(self):
		g = nx.Graph()
		for node in dfs_nodes(self):
			if node.left:
				g.add_edge(node.data, node.left.data)
			if node.right:
				g.add_edge(node.data, node.right.data)

		return g

	def get_positions(node, positions, x, y):
		if node:
			node_size = 0.5

			my_x = (x[1] + x[0]) / 2
			my_y = y[0] + (node_size / 2)

			positions[node.data] = (my_x, -my_y)
			Tree.get_positions(node.left, positions, (x[0], my_x), (my_y, y[1]))
			Tree.get_positions(node.right, positions, (my_x, x[1]), (my_y, y[1]))

	def draw(self):
		positions = {}
		Tree.get_positions(self, positions, x=(0, 10), y=(0, 10))

		print(positions)

		g = self.to_graph()

		plt.axis('on')
		color = 'b' if self.is_black else 'r'
		nx.draw_networkx(g, positions, node_size=1500, font_size=24, node_color='g')
		plt.show()

def is_bst(tree):
	if not tree:
		return True

	left_ok = (not tree.left) or \
			(tree.left and max_node(tree.left) <= tree)
	right_ok = (not tree.right) or \
			(tree.right and tree < min_node(tree.right))
	return left_ok and right_ok and \
		is_bst(tree.left) and is_bst(tree.right) 

def min_node_recursce(bst):
	assert is_bst(bst)

	if not bst.left:
		return bst

	return min_node_recursce(bst.left)

def min_node(bst):
	if bst:
		if bst.left and bst.right:
			return min(min_node(bst.left), min_node(bst.right)) 
		elif bst.left:
			return bst.left
		elif bst.right:
			return bst.right
		else:
			return bst
	return bst

def max_node(bst):
	if bst:
		if bst.left and bst.right:
			return max(min_node(bst.left), min_node(bst.right)) 
		elif bst.left:
			return bst.left
		elif bst.right:
			return bst.right
		else:
			return bst
	return bst

def next_node(bst):
	assert is_bst(bst)

	if bst.right:
		return min_node(bst.right)

	if bst.parent.left == bst:
		return bst.parent

	while bst.parent and bst.parent.right == bst:
		bst = bst.parent

	return bst.parent

def prev_node(bst):
	if bst.left:
		return max_node(bst.left)

	if bst.parent.right == bst:
		return bst.parent

	if bst.parent.right and bst.parent.left == bst:
		bst = bst.parent
	return bst.parent

begin = min_node

def end(bst):
	return None

def iterator(bst):
	it = begin(bst)
	while it != end(bst):
		print("it = ", bst)
		yield it
		it = next_node(it)

def lower_bound(bst, x):
	assert is_bst(bst)
	
	if bst:
		if x < bst.data:
			res = lower_bound(bst.left, x)
			if res:
				bst = res
		elif bst.data < x:
			return lower_bound(bst.right, x)
	return bst


def insert(tree, x):
	assert is_bst(tree)

	if not tree:
		return Tree(x)

	if x < tree.data:
		if tree.left:
			return insert(tree.left, x)
		else:
			tree.left = Tree(x)
			tree.left.parent = tree
			return tree.left
	elif tree.data < x:
		if tree.right:
			return insert(tree.right, x)
		else:
			tree.right = Tree(x)
			tree.right.parent = tree
			return tree.right

	return tree

def dfs_nodes(tree):
	if tree:
		yield from dfs_nodes(tree.left)
		yield tree
		yield from dfs_nodes(tree.right)

def remove(tree, x):
	#place = find(tree, x)
	#rotate_left(rotate_left(place)()
	#place = find(tree, x)
	pass

def rotate_left(node):
	if node and node.right:
		new_root = node.right
		node_left = node.right.left
		node.right = node_left
		new_root.left = node
		return node

def insert_rb_tree(tree, x):
	assert(is_rbtree(tree))

	node = insert(tree, x)
	if is_black(tree):



def create_tree_1():
	return Tree(10, 
		Tree(4, 
			Tree(3), 
			Tree(5,
				Tree(5)
				)
			), 
		Tree(20,
			Tree(15,
				right=Tree(17,
							Tree(16),
							Tree(18, 
								right=Tree(19)
								)
							)
				)
			)
		)

def create_tree_2():
	return Tree(8, 
		Tree(3, 
			Tree(1), 
			Tree(6,
				Tree(4),
				Tree(7)
				)
			), 
		Tree(10,
			right=Tree(14,
						Tree(13)
				)
			)
		)

def create_tree_3():
	return Tree(3, 
			Tree(2),
			Tree(5,
				Tree(1),
				Tree(7))
			)

def main():
	t = create_tree_1()
	t2 = create_tree_2()
	t3 = create_tree_3()

	#print("min_node() is "+str(min_node(t3.right)))
	print("Good tree1 is_bst() is "+str(is_bst(t)))
	print("Good tree2 is_bst() is "+str(is_bst(t)))
	print("Bad tree3 is_bst() is "+str(is_bst(t3)))
	print(lower_bound(t2, 10))

	for i in range(25):
		print("Insert "+str(i))
		insert(t2, i)
		print(", ".join(map(str, dfs_nodes(t2))))
	t.draw()

if __name__ == '__main__':
	main()
