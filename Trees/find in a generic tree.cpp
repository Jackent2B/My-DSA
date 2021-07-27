bool isPresent(Node* root, int num){
	if(root->data == num)
		return true;
	// pic = present in child
	for(auto child: root->children){
		bool pic = isPresent(child,data);
		if(pic){
			return true;
		}
	}
	return false;
}