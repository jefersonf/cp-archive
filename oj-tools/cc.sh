#!/bin/bash

contestID=$1
tasks=$2
dir=$3

DEFAULT_CONTEST_ID="unknown"
ALL_TASKS="ABCDEFG"
DIR="."

[ -z $contestID ] && contestID=$DEFAULT_CONTEST_ID
[ -z $tasks ] && tasks=$ALL_TASKS
[ -z $dir ] && dir=$DIR

n=${#tasks}
echo "Creating contest" $contestID \
	"(tasks from ${tasks:0:1} to ${tasks:($n-1):$n})"

contest_dir="${dir}/${contestID}"
create_contest_folder=(mkdir -p $contest_dir)

${create_contest_folder[@]}
for t in $(seq 1 $n); do
	task_file="${tasks:($t-1):1}.cpp"
	task_path="${contest_dir}/${task_file}"
	create_task=(cp ./template.cpp "${task_path}")
	${create_task[@]}
done