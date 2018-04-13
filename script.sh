for filename in $1/*; do
  echo $filename

  if ! ([[ $filename = *".java"* ]] || [[ $filename = *".cpp"* ]]); then
      mv "$filename" "$filename.cpp"
  fi

done
