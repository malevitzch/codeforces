for file in *.cpp; do
  target_dir=$(echo "$file" | sed -n 's/^\([0-9]\+\).*$/\1/p')
  if [ -n "$target_dir" ]; then
    mkdir -p "$target_dir"
    mv "$file" "$target_dir/"
  fi
done
