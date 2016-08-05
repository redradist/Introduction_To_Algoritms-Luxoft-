import tree_lib

class Tree:
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right
		self.parent = None

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

	def __str__(self):
		return str(self.data)

	def nodes(self):
		yield from dfs_pre_order(self)

	def to_graph(self):
		G = Graph()
		def visitor(node):
			if node.data not in G.adjList:
				G.add_single_vertex(node.data)
			if node.left:
				G.add_edges((node.data, node.left.data))
			if node.right:
				G.add_edges((node.data, node.right.data))

		traverse_pre_order(self, visitor)
		return G

def is_bst(tree):
	if not tree:
		return True

	left_ok = not tree.left or tree.left < tree
	right_ok = not tree.right or tree < tree.right

	return 	left_ok and right_ok and \
		is_bst(tree.left) and is_bst(tree.right)

def min_node_recursce(bst):
	assert is_bst(bst) and bst is not None

	if not bst.left:
		return bst

	return min_node_recursce(bst.left)

def min_node(bst):
	assert is_bst(bst) and bst is not None

	while bst.left:
		bst = bst.left
	return bst

def max_node(bst):
	assert is_bst(bst) and bst is not None

	while bst.right:
		bst = bst.right
	return bst

def next_node(bst):
	if bst.right:
		min_node(bst.right)
	return bst.parent

def prev_node(bst):
	if bst.left:
		max_node(bst.right)
	return bst.parent

begin = min_node

def end(bst):
	return None

def iterator(bst):
	it = begin(bst)
	while it != end(bst):
		yield it
		it = next_node(it)

def lower_bound_1(bst, x):
	assert is_bst(bst)
	if bst:
		if bst.data < x:
			return lower_bound(bst.right, x)
		if x < bst.data:
			result = lower_bound(bst.left, x)
			if result:
				return result
		return bst
	else:
		return None


def lower_bound_2(bst, x):
	#assert is_bst(bst)
	if not bst:
		return bst
	
	if x < bst.data:
		result = lower_bound_2(bst.left, x)
	else:
		result = lower_bound_2(bst.right, x)

	if not result:
		return bst
	return result

def lower_bound_3(bst, x):
	assert is_bst(bst) and bst is not None

	

def insert(tree, x):
	place = lower_bound(tree, x)


def dfs_nodes(tree):
	if tree:
		yield from dfs_nodes(tree.left)
		yield tree
		yield from dfs_nodes(tree.right)


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
				right=Tree(13)
				)
			)
		)


def main():
	t = create_tree_1()

	print(lower_bound_2(t, 10))
	print(", ".join(map(str, dfs_nodes(t))))

if __name__ == '__main__':
	main()
