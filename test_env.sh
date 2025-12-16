#!/bin/bash
# Simulate the test: remove all env vars except one and run env
env -i TEST_VAR=test_value ./hsh << 'EOF'
env
EOF
