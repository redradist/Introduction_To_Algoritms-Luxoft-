

class Tree:
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right

	def __str__(self):
		return str(self.data)

	def nodes(self):
		yield from dfs(self)

def dfs(tree):
	if tree:
		yield tree
		yield from traverse_pre_order(tree.left, visitor)
		yield from traverse_pre_order(tree.right, visitor)

def foo():
	db = { k : v for k, v in db.items() }
	db["data"] = "asdsadafas" 

def strTree(t):
	if t != None:
		result = ""
		if t.data != None:
			result = result + str(t.data) + " \n"
		result = result + strTree(t.left) + " \n"
		result = result + strTree(t.right) + " \n"
		return result
	else:
		return "None"

def traverse_pre_order(tree, visitor):
	if tree:
		visitor(tree)
		traverse_pre_order(tree.left, visitor)
		traverse_pre_order(tree.right, visitor)

def traverse_in_order(tree, visitor):
	if tree:
		traverse_pre_order(tree.left, visitor)
		visitor(tree)
		traverse_pre_order(tree.right, visitor)

def traverse_post_order(tree, visitor):
	if tree:
		traverse_pre_order(tree.left, visitor)
		traverse_pre_order(tree.right, visitor)
		visitor(tree)

def printTree0(t):
	if t != None:
		if t.data != None:
			print(t.data)
		printTree0(t.left)
		printTree0(t.right)

def printTree1(t):
	if t != None:
		printTree1(t.left)
		if t.data != None:
			print(t.data)
		printTree1(t.right)

def printTree2(t):
	if t != None:
		printTree2(t.left)
		printTree2(t.right)
		if t.data != None:
			print(t.data)

def co_numbers(max, pred):
	for i in range(max):
		if pred(i):
			yield i

def main():

	def divided_by_3():
		for i in co_numbers(10, lambda x: x%3==0):
			print(i)

	for i in divided_by_3():
		print(i)
	return

	t = Tree(1, 
			Tree(2, 
				Tree(4), 
				Tree(5,
					Tree(8))), 
			Tree(3,
				Tree(6),
				Tree(7,
					Tree(9,
						Tree(10)))))
	#printTree0(t)
	#printTree1(t)
	#printTree2(t)
	#print(t)
	traverse_pre_order(t, print)
	traverse_in_order(t, print)
	traverse_post_order(t, print)

	for node in t.nodes() :
		print(node)

if __name__ == '__main__':
	main()
