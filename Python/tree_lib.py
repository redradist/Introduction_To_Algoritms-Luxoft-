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
