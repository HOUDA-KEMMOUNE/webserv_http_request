ADD = git add .
COMMIT = git commit -m "update"
PUSH = git push

all:
	$(ADD) && $(COMMIT) && $(PUSH)
